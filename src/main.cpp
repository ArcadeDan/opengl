#include <iostream>
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE == GLFW_PRESS)) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main ( int argc, char* argv[] ) {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
        return EXIT_FAILURE;
    }

    glViewport(0, 0, 800, 600);
   

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
    
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }



    glfwTerminate();
    std::cout << "Goodbye Cruel World!\n";
    return EXIT_SUCCESS;
}