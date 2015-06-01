#ifndef ENGINE_MATRIX_H
#define ENGINE_MATRIX_H

typedef float Mat4[4][4];

void mat4_zero(Mat4 out);
void mat4_identity(Mat4 out);
void mat4_multiply(Mat4 out, Mat4 l, Mat4 r);
void mat4_perspective(Mat4 out, float fov, float aspect, float near, float far);

void mat4_translate(Mat4 out, float pos[3]);
void mat4_rotate(Mat4 out, float rot[3]);
void mat4_rotatex(Mat4 out, float angle);
void mat4_rotatey(Mat4 out, float angle);
void mat4_rotatez(Mat4 out, float angle);

#endif // ENGINE_MATRIX_H
