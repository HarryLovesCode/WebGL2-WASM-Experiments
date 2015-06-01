#ifndef ENGINE_CALLBACKS_H
#define ENGINE_CALLBACKS_H

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void glfw_error_callback(int error, const char* description);
void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif // ENGINE_CALLBACKS_H
