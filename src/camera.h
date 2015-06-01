#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H
#include "matrix.h"

typedef struct {
	// Viewport values
    float fov;    // Viewport FOV in radians
    float near;   // Distance from camera to z near clipping plane
    float far;	  // Distance from camera to z far clipping plane
    float aspect; // Viewport width / Viewport height

	// Matrices
    Mat4 m_pro;	// Projection matrix
    Mat4 m_pos;	// Position matrix
    Mat4 m_rot;	// Rotation matrix
    Mat4 m_mod;	// Model view matrix

    // Vectors
    float v_pos[3]; // Position (for updating m_pos matrix)
    float v_rot[3]; // Rotation (for updating m_rot matrix)
} Camera;

Camera camera_create(float fov, int width, int height, float near, float far);

void camera_aspect(Camera *camera, int width, int height);
void camera_update(Camera *camera);

void camera_translate(Camera *camera, float x, float y, float z);
void camera_translation(Camera *camera, float x, float y, float z);

void camera_rotate(Camera *camera, float x, float y, float z);
void camera_rotation(Camera *camera, float x, float y, float z);

#endif // ENGINE_CAMERA_H
