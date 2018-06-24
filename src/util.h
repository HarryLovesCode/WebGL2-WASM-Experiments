#ifndef ENGINE_UTIL_H
#define ENGINE_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <GLES3/gl3.h>

GLuint create_shader(GLenum type, const char* source);
GLuint create_program(GLuint vert_shader, GLuint frag_shader);

GLuint load_shader(GLenum type, const char *path);
GLuint load_program(const char *v_path, const char *f_path);
GLuint load_texture(const char *path);

#endif // ENGINE_UTIL_H
