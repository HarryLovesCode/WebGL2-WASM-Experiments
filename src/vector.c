#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void vec_init(Vec *vec)
{
    vec->used = 0;
    vec->size = 2;
    vec->data = malloc(vec->size * sizeof(float));
}

void vec_free(Vec *vec)
{
    free(vec->data);
}

void vec_resize(Vec *vec)
{
    vec->size *= 2;
    vec->data = realloc(vec->data, vec->size * sizeof(float));
}

float vec_get(Vec *vec, int idx)
{
    return vec->data[idx];
}

void vec_append(Vec *vec, float val)
{
    if (vec->used >= vec->size)
        vec_resize(vec);

    vec->data[vec->used++] = val;
}
