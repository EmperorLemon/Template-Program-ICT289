#ifndef LIST_H
#define LIST_H

#include "Object.h"

typedef struct node Node;
typedef struct list List;

List* CreateList();

void DisplayList(List* list);

void AddObject(Object data, List* list);

void RemoveObject(int key, List* list);

void ReplaceObject(int key, Object* newData, List* list);

Object FindObject(int key, List* list);

Object* ToArray(List* list);

int Size(List* list);

void DestroyList(List* list);

#endif // LIST_H
