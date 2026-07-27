//--- OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//--- include
#include <iostream>

//--- Macros
#define HEIGHT 600
#define WIDTH 800

int main() {
  glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);
  if (!glfwInit()) {
    std::cerr << "Failed to initializes GLFW" << std::endl;
    return -1;
  }
  
  GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "TEST", NULL, NULL);
  if (!window) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    return -1;
  }

  glfwMakeContextCurrent(window);

  gladLoadGL();

  glViewport(0, 0, WIDTH, HEIGHT);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
