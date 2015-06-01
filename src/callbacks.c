#include "callbacks.h"

void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "%s\n", description);
}

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
