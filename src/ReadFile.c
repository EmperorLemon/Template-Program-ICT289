// Program: ReadFile.c
// Creator: Caleb Goss
// Purpose: I can't read, so I'm not sure

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ReadFile.h"

#define STRING_LENGTH 24

Mesh readMeshFile(char *fileName)
{
    Mesh mesh;

    char dataPath[] = "./data/";
    char fileExtension[] = ".off";

    strcat(dataPath,fileName);
    strcat(dataPath,fileExtension);

    FILE *mFile = fopen(dataPath,"r");

    if (mFile == NULL)
    {
        printf("Error: file could not be opened!\nPress any key to exit...");
        getchar();
        exit(-1);
    }

    char fileCheck[STRING_LENGTH];
    fscanf(mFile, "%s", fileCheck);

    if (strcmp(fileCheck, "OFF") != 0)
    {
        fclose(mFile);
        printf("Error: invalid file format!\nPress any key to exit...");
        getchar();
        exit(-1);
    }

    int dump;
    fscanf(mFile, "%d %d %d", &mesh.nverts, &mesh.nfaces, &dump);

    mesh.verts = (Vector3*) malloc(mesh.nverts * sizeof(Vector3));

    for (int i = 0; i < mesh.nverts; i++)
        fscanf(mFile, "%f %f %f", &mesh.verts[i].x, &mesh.verts[i].y, &mesh.verts[i].z);

    mesh.faces = (Face*) malloc(mesh.nfaces * sizeof(Face));
    mesh.normals = (Vector3*) malloc(mesh.nfaces * sizeof(Vector3));

    for (int i = 0; i < mesh.nfaces; i++)
        fscanf(mFile, "%d %d %d %d", &dump, &mesh.faces[i][0], &mesh.faces[i][1], &mesh.faces[i][2]);

    fclose(mFile);

    return mesh;
}

void testDisplayMesh(const Mesh* m)
{
    char p1, p2;

    printf("\nPress Enter to view vertex data:\n");

    p1 = getchar();

    if (p1 == '\n')
        for (int i = 0; i < m->nverts; i++)
            printf("%f %f %f\n", m->verts[i].x, m->verts[i].y, m->verts[i].z);

    printf("\nPress Enter to view face data:\n");
    p2 = getchar();

    if (p2 == '\n')
        for (int i = 0; i < m->nfaces; i++)
            printf("%d %d %d\n", m->faces[i][0], m->faces[i][1], m->faces[i][2]);
}
