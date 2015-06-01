#include "matrix.h"
#include <math.h>

void mat4_zero(Mat4 out)
{
    out[0][0] = 0.0f;
    out[0][1] = 0.0f;
    out[0][2] = 0.0f;
    out[0][3] = 0.0f;

    out[1][0] = 0.0f;
    out[1][1] = 0.0f;
    out[1][2] = 0.0f;
    out[1][3] = 0.0f;

    out[2][0] = 0.0f;
    out[2][1] = 0.0f;
    out[2][2] = 0.0f;
    out[2][3] = 0.0f;

    out[3][0] = 0.0f;
    out[3][1] = 0.0f;
    out[3][2] = 0.0f;
    out[3][3] = 0.0f;
}

void mat4_identity(Mat4 out)
{
    out[0][0] = 1.0f;
    out[0][1] = 0.0f;
    out[0][2] = 0.0f;
    out[0][3] = 0.0f;

    out[1][0] = 0.0f;
    out[1][1] = 1.0f;
    out[1][2] = 0.0f;
    out[1][3] = 0.0f;

    out[2][0] = 0.0f;
    out[2][1] = 0.0f;
    out[2][2] = 1.0f;
    out[2][3] = 0.0f;

    out[3][0] = 0.0f;
    out[3][1] = 0.0f;
    out[3][2] = 0.0f;
    out[3][3] = 1.0f;
}

void mat4_translate(Mat4 out, float pos[3])
{
    out[0][0] = 1.0f;
    out[0][1] = 0.0f;
    out[0][2] = 0.0f;
    out[0][3] = 0.0f;

    out[1][0] = 0.0f;
    out[1][1] = 1.0f;
    out[1][2] = 0.0f;
    out[1][3] = 0.0f;

    out[2][0] = 0.0f;
    out[2][1] = 0.0f;
    out[2][2] = 1.0f;
    out[2][3] = 0.0f;

    out[3][0] = pos[0];
    out[3][1] = pos[1];
    out[3][2] = pos[2];
    out[3][3] = 1.0f;
}

void mat4_multiply(Mat4 out, Mat4 l, Mat4 r)
{
    float l00 = l[0][0];
    float l01 = l[0][1];
    float l02 = l[0][2];
    float l03 = l[0][3];

    float l04 = l[1][0];
    float l05 = l[1][1];
    float l06 = l[1][2];
    float l07 = l[1][3];

    float l08 = l[2][0];
    float l09 = l[2][1];
    float l10 = l[2][2];
    float l11 = l[2][3];

    float l12 = l[3][0];
    float l13 = l[3][1];
    float l14 = l[3][2];
    float l15 = l[3][3];

    float t0 = r[0][0];
    float t1 = r[0][1];
    float t2 = r[0][2];
    float t3 = r[0][3];

    out[0][0] = t0 * l00 + t1 * l04 + t2 * l08 + t3 * l12;
    out[0][1] = t0 * l01 + t1 * l05 + t2 * l09 + t3 * l13;
    out[0][2] = t0 * l02 + t1 * l06 + t2 * l10 + t3 * l14;
    out[0][3] = t0 * l03 + t1 * l07 + t2 * l11 + t3 * l15;

    t0 = r[1][0];
    t1 = r[1][1];
    t2 = r[1][2];
    t3 = r[1][3];

    out[1][0] = t0 * l00 + t1 * l04 + t2 * l08 + t3 * l12;
    out[1][1] = t0 * l01 + t1 * l05 + t2 * l09 + t3 * l13;
    out[1][2] = t0 * l02 + t1 * l06 + t2 * l10 + t3 * l14;
    out[1][3] = t0 * l03 + t1 * l07 + t2 * l11 + t3 * l15;

    t0 = r[2][0];
    t1 = r[2][1];
    t2 = r[2][2];
    t3 = r[2][3];

    out[2][0] = t0 * l00 + t1 * l04 + t2 * l08 + t3 * l12;
    out[2][1] = t0 * l01 + t1 * l05 + t2 * l09 + t3 * l13;
    out[2][2] = t0 * l02 + t1 * l06 + t2 * l10 + t3 * l14;
    out[2][3] = t0 * l03 + t1 * l07 + t2 * l11 + t3 * l15;

    t0 = r[3][0];
    t1 = r[3][1];
    t2 = r[3][2];
    t3 = r[3][3];

    out[3][0] = t0 * l00 + t1 * l04 + t2 * l08 + t3 * l12;
    out[3][1] = t0 * l01 + t1 * l05 + t2 * l09 + t3 * l13;
    out[3][2] = t0 * l02 + t1 * l06 + t2 * l10 + t3 * l14;
    out[3][3] = t0 * l03 + t1 * l07 + t2 * l11 + t3 * l15;
}

void mat4_perspective(Mat4 out, float fov, float aspect, float near, float far)
{
    float p = 1.0f / (near - far);
    float f = 1.0f / (float) tan((double) fov / 2.0);

    out[0][0] = f / aspect;
    out[0][1] = 0.0f;
    out[0][2] = 0.0f;
    out[0][3] = 0.0f;

    out[1][0] = 0.0f;
    out[1][1] = f;
    out[1][2] = 0.0f;
    out[1][3] = 0.0f;

    out[2][0] = 0.0f;
    out[2][1] = 0.0f;
    out[2][2] = (far + near) * p;
    out[2][3] = -1.0f;

    out[3][0] = 0.0f;
    out[3][1] = 0.0f;
    out[3][2] = 2.0f * far * near * p;
    out[3][3] = 1.0f;
}

void mat4_rotate(Mat4 out, float rot[3]) 
{
    float cx = cos(rot[0]);
    float sx = sin(rot[0]);
    
    float cy = cos(rot[1]);
    float sy = sin(rot[1]);

    float cz = cos(rot[2]);
    float sz = sin(rot[2]);

    out[0][0] = cy * cz;
    out[0][1] = -cy * sz;
    out[0][2] = sy;
    out[0][3] = 0.0f;

    out[1][0] = sx * sy * cz + cx * sz;
    out[1][1] = -sx * sy * sz + cx * cz;
    out[1][2] = -sx * cy;
    out[1][3] = 0.0f;

    out[2][0] = -cx * sy * cz + sx * sz;
    out[2][1] = cx * sy * sz + sx * cz;
    out[2][2] = cx * cy;
    out[2][3] = 0.0f;

    out[3][0] = 0.0f;
    out[3][1] = 0.0f;
    out[3][2] = 0.0f;
    out[3][3] = 1.0f;   
}

void mat4_rotatex(Mat4 out, float angle)
{
    float c = cos(angle);
    float s = sin(angle);

    out[0][0] = 1.0f;
    out[0][1] = 0.0f;
    out[0][2] = 0.0f;
    out[0][3] = 0.0f;

    out[1][0] = 0.0f;
    out[1][1] = c;
    out[1][2] = s;
    out[1][3] = 0.0f;

    out[2][0] = 0.0f;
    out[2][1] = -s;
    out[2][2] = c;
    out[2][3] = 0.0f;

    out[3][0] = 0.0f;
    out[3][1] = 0.0f;
    out[3][2] = 0.0f;
    out[3][3] = 1.0f;
}

void mat4_rotatey(Mat4 out, float angle)
{
    float c = cos(angle);
    float s = sin(angle);

    out[0][0] = c;
    out[0][1] = 0.0f;
    out[0][2] = -s;
    out[0][3] = 0.0f;

    out[1][0] = 0.0f;
    out[1][1] = 1.0f;
    out[1][2] = 0.0f;
    out[1][3] = 0.0f;

    out[2][0] = s;
    out[2][1] = 0.0f;
    out[2][2] = c;
    out[2][3] = 0.0f;

    out[3][0] = 0.0f;
    out[3][1] = 0.0f;
    out[3][2] = 0.0f;
    out[3][3] = 1.0f;
}

void mat4_rotatez(Mat4 out, float angle)
{
    float c = cos(angle);
    float s = sin(angle);

    out[0][0] = c;
    out[0][1] = s;
    out[0][2] = 0.0f;
    out[0][3] = 0.0f;

    out[1][0] = -s;
    out[1][1] = c;
    out[1][2] = 0.0f;
    out[1][3] = 0.0f;

    out[2][0] = 0.0f;
    out[2][1] = 0.0f;
    out[2][2] = 1.0f;
    out[2][3] = 0.0f;

    out[3][0] = 0.0f;
    out[3][1] = 0.0f;
    out[3][2] = 0.0f;
    out[3][3] = 1.0f;
}

