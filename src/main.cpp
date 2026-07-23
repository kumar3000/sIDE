#include <glad/glad.h>
#include <GLFW/glfw3.h>

void render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // Add your drawing calls here
}

// Callback for window position (smooth dragging)
void window_pos_callback(GLFWwindow* window, int xpos, int ypos) {
    render();
    glfwSwapBuffers(window);
}

// Callback for window size (smooth resizing)
void window_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    render();
    glfwSwapBuffers(window);
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Smooth Drag", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    // Set callbacks
    glfwSetWindowPosCallback(window, window_pos_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        render();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
