#include "util.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint create_shader(GLenum type, const char *source)
{
    GLint success = GL_FALSE;
    GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (success == GL_FALSE)
    {
        GLchar *info_log;
        GLint max_len = 0;

        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &max_len);
        info_log = calloc(max_len + 1, sizeof(GLchar));
        glGetShaderInfoLog(shader, max_len, &max_len, &info_log[0]);

        fprintf(stderr, "Failed to compile shader: %s\n", info_log);
        free(info_log);

        exit(EXIT_FAILURE);
    }

    return shader;
}

GLuint create_program(GLuint vert_shader, GLuint frag_shader)
{
    GLint success = GL_FALSE;
    GLuint program = glCreateProgram();

    glAttachShader(program, vert_shader);
    glAttachShader(program, frag_shader);

    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (success == GL_FALSE)
    {
        GLchar *info_log;
        GLint max_len = 0;

        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &max_len);
        info_log = calloc(max_len + 1, sizeof(GLchar));
        glGetProgramInfoLog(program, max_len, &max_len, &info_log[0]);

        fprintf(stderr, "Failed to link program: %s\n", info_log);
        free(info_log);

        exit(EXIT_FAILURE);
    }

    return program;
}

GLuint load_shader(GLenum type, const char *path)
{
    int len = 0;
    char *source;
    GLuint shader;
    FILE *file = fopen(path, "rb");

    if (!file)
    {
        fprintf(stderr, "Failed to open file: %s\n", path);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    len = ftell(file);
    fseek(file, 0, SEEK_SET);

    source = calloc(len + 1, sizeof(char));
    fread(source, 1, len, file);
    fclose(file);

    shader = create_shader(type, source);

    free(source);
    return shader;
}

GLuint load_program(const char *v_path, const char *f_path)
{
    GLuint vs = load_shader(GL_VERTEX_SHADER, v_path);
    GLuint fs = load_shader(GL_FRAGMENT_SHADER, f_path);

    GLuint out = create_program(vs, fs);

    return out;
}

GLuint load_texture(const char *path)
{
    GLuint tex;
    int x, y, n;
    stbi_set_flip_vertically_on_load(1);
    unsigned char *data = stbi_load(path, &x, &y, &n, 0);

    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);
    return tex;
}
