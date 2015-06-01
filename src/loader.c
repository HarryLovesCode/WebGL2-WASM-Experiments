#include "loader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mesh_load(Mesh *mesh, char *path)
{
    mesh->has_n = 0;
    mesh->has_u = 0;
    mesh->draw_count = 0;

    vec_init(&mesh->v_data);
    vec_init(&mesh->n_data);
    vec_init(&mesh->u_data);

    vec_init(&mesh->v_comp_data);
    vec_init(&mesh->n_comp_data);
    vec_init(&mesh->u_comp_data);

    FILE *file = fopen(path, "rb");
    char *line = calloc(1024, sizeof(char));

    while (fgets(line, 1024, file)) {
        if (strncmp("v ", line, 2) == 0) {
            mesh_parse_3f(&mesh->v_comp_data, line);
        } else if (strncmp("vn", line, 2) == 0) {
            mesh->has_n = 1;
            mesh_parse_3f(&mesh->n_comp_data, line);
        } else if (strncmp("vt", line, 2) == 0) {
            mesh->has_u = 1;
            mesh_parse_2f(&mesh->u_comp_data, line);
        } else if (strncmp("f ", line, 2) == 0) {
            mesh->draw_count += 3;
            mesh_parse_face(mesh, line);
        }
    }

    fclose(file);

    mesh->v_size = mesh->v_data.size * sizeof(float);
    mesh->n_size = mesh->n_data.size * sizeof(float);
    mesh->u_size = mesh->u_data.size * sizeof(float);
}

void mesh_parse_2f(Vec *data, char *str_seq)
{
    float x, y;

    sscanf(str_seq, "%*s %f %f", &x, &y);
    vec_append(data, x);
    vec_append(data, y);
}

void mesh_parse_3f(Vec *data, char *str_seq)
{
    float x, y, z;

    sscanf(str_seq, "%*s %f %f %f", &x, &y, &z);
    vec_append(data, x);
    vec_append(data, y);
    vec_append(data, z);
}

void mesh_parse_face(Mesh *mesh, char *line)
{
    int v = 0;
    int u = 0;
    int n = 0;
    char *token = NULL;

    token = strtok(line, " ");

    while (token) {
        if (strcmp(token, "f") != 0) {
            if (mesh->has_n && mesh->has_u) {
                sscanf(token, "%d/%d/%d", &v, &u, &n);
                mesh_append_face(&mesh->v_data, &mesh->v_comp_data, v, 3);
                mesh_append_face(&mesh->u_data, &mesh->u_comp_data, u, 2);
                mesh_append_face(&mesh->n_data, &mesh->n_comp_data, n, 3);
            } else if (mesh->has_n && !mesh->has_u) {
                sscanf(token, "%d//%d", &v, &n);
                mesh_append_face(&mesh->v_data, &mesh->v_comp_data, v, 3);
                mesh_append_face(&mesh->n_data, &mesh->n_comp_data, n, 3);
            } else if (!mesh->has_n && mesh->has_u) {
                sscanf(token, "%d/%d", &v, &u);
                mesh_append_face(&mesh->v_data, &mesh->v_comp_data, v, 3);
                mesh_append_face(&mesh->u_data, &mesh->u_comp_data, u, 2);
            } else if (!mesh->has_n && !mesh->has_u) {
                sscanf(token, "%d", &v);
                mesh_append_face(&mesh->v_data, &mesh->v_comp_data, v, 3);
            }
        }

        token = strtok(NULL, " ");
    }
}

void mesh_append_face(Vec *new, Vec *old, int idx, int len)
{
    for (int i = 0; i < len; ++i)
        vec_append(new, vec_get(old, (idx - 1) * len + i));
}
