#ifndef ENGINE_LOADER_H
#define ENGINE_LOADER_H
#include "vector.h"

typedef struct {
    Vec v_data;
    Vec n_data;
    Vec u_data;

    Vec v_comp_data;
    Vec n_comp_data;
    Vec u_comp_data;

    int has_n;
    int has_u;

    unsigned int v_size;
    unsigned int n_size;
    unsigned int u_size;
    unsigned int draw_count;
} Mesh;

void mesh_load(Mesh *mesh, char *path);
void mesh_parse_2f(Vec *data, char *str_seq);
void mesh_parse_3f(Vec *data, char *str_seq);
void mesh_parse_face(Mesh *mesh, char *line);
void mesh_append_face(Vec *target, Vec *source, int idx, int len);

#endif // ENGINE_LOADER_H
