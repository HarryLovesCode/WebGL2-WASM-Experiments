#ifndef ENGINE_VECTOR_H
#define ENGINE_VECTOR_H

typedef struct {
    float *data;
    int used; // Indices occupied
    int size; // Current size of list
} Vec;

void vec_init(Vec *vec);
void vec_free(Vec *vec);
void vec_resize(Vec *vec);
void vec_append(Vec *vec, float val);

float vec_get(Vec *vec, int idx);

#endif // ENGINE_VECTOR_H
