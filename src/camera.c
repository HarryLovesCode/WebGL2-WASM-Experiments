#include "camera.h"
#include <string.h>

Camera camera_create(float fov, int width, int height, float near, float far)
{
    Camera out = {
        .fov = fov,
        .near = near,
        .far = far,

        .m_pro = {{ 0 }},
        .m_pos = {{ 0 }},
        .m_rot = {{ 0 }},

        .v_pos = { 0 },
        .v_rot = { 0 }
    };

    camera_update(&out);

    return out;
}

void camera_aspect(Camera *camera, int width, int height)
{
    camera->aspect = (float) width / (float) height;
}

void camera_translate(Camera *camera, float x, float y, float z)
{
    camera->v_pos[0] += x;
    camera->v_pos[1] += y;
    camera->v_pos[2] += z;
}

void camera_translation(Camera *camera, float x, float y, float z)
{
    camera->v_pos[0] = x;
    camera->v_pos[1] = y;
    camera->v_pos[2] = z;
}

void camera_rotate(Camera *camera, float x, float y, float z)
{
    camera->v_rot[0] = +x;
    camera->v_rot[1] = +y;
    camera->v_rot[2] = +z;
}

void camera_rotation(Camera *camera, float x, float y, float z)
{
    camera->v_rot[0] = x;
    camera->v_rot[1] = y;
    camera->v_rot[2] = z;
}

void camera_update(Camera *camera)
{
    mat4_perspective(
        camera->m_pro,
        camera->fov,
        camera->aspect,
        camera->near,
        camera->far);
    mat4_translate(camera->m_pos, camera->v_pos);
    mat4_rotate(camera->m_rot, camera->v_rot);
    //mat4_multiply(camera->m_mod, camera->m_rot, camera->m_pos); Perspective
    mat4_multiply(camera->m_mod, camera->m_pos, camera->m_rot);
}
