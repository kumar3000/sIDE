#include <iostream>

// GLAD must be included before GLFW!
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// ImGui headers
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

int main() {
    // 1. Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Set OpenGL profile to Core 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui + GLFW + GLAD Example", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable v-sync

    // 2. Initialize GLAD loader
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    // 3. Initialize ImGui Context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Optional: Enable keyboard controls

    // Set style (Dark theme by default)
    ImGui::StyleColorsDark();

    // 4. Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // State variables for UI
    float color[3] = { 0.1f, 0.1f, 0.1f };
    int counter = 0;

    // 5. Main Loop
    while (!glfwWindowShouldClose(window)) {
        // Poll input events
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Create a simple window window
        {
            ImGui::Begin("Debug Panel");
            ImGui::Text("Welcome to ImGui!"); 
            
            // Slider to modify background color
            ImGui::ColorEdit3("Background Color", color);
            
            // Button with a counter
            if (ImGui::Button("Click Me")) {
                counter++;
            }
            ImGui::SameLine();
            ImGui::Text("Count = %d", counter);

            // Display current framerate
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }

        // Rendering ImGui
        ImGui::Render();
        
        // Clear OpenGL buffer with our color variable
        glViewport(0, 0, 1280, 720);
        glClearColor(color[0], color[1], color[2], 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render ImGui draw data over the empty background
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap window buffers
        glfwSwapBuffers(window);
    }

    // 6. Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
