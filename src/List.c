#include "../include/List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Big thanks to:
 https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm
 https://github.com/skorks/c-linked-list
*/

struct node
{
    Object data;
    int key;
    struct node* next;
};

struct list
{
    Node* head;
};

Node* CreateNode(Object* data, int key);

Node* CreateNode(Object* data, int key)
{
    Node* newNode = (Node*) malloc(sizeof(Node));

    // if not enough mem alloc
    if (!newNode)
        return NULL;

    newNode->data = (*data);
    newNode->key = key;
    newNode->next = NULL;

    return newNode;
}

List* CreateList()
{
    List* list = (List*) malloc(sizeof(List));

    // if not enough mem alloc
    if (!list)
        return NULL;

    list->head = NULL;

    return list;
}

void AddObject(Object data, List* list)
{
    Node* current = NULL;

    if (list->head == NULL)
        list->head = CreateNode(&data, 0);
    else
    {
        current = list->head; // start first position

        while (current->next != NULL) // if the next element is not null
            current = current->next; // set the current node to the next node

        current->next = CreateNode(&data, Size(list)); // otherwise, create another node
    }
}

Node* FindByKey(Node *head, int key);

Node* FindByKey(Node* head, int key)
{
    Node* current = head;

    if (current == NULL)
    {
        printf("Have you even made a list yet?\n");
        exit(-1);
    }

    while (current->key != key)
    {
        if (current->next == NULL)
        {
            printf("This object does not exist!\n");
            exit(-2);
        }
        else
            current = current->next;
    }

    return current;
}

Object FindObject(int key, List *list)
{
    return FindByKey(list->head, key)->data;
}

void DisplayList(List* list)
{
    Node* current = list->head;
    printf("\n[ ");

    while(current != NULL)
    {
        printf("(%d,%s) ", current->key, current->data.name);
        current = current->next;
    }

    printf("]");
}

int listSize(Node *top);

int listSize(Node *top)
{
    if (top == NULL)
        return 0;
    else
        return 1 + listSize(top->next);
}

int Size(List *list)
{
    return listSize(list->head);
}

void ReplaceObject(int key, Object* newData, List* list)
{
    Node* current = list->head;

    while (current != NULL)
    {
        if (current->key == key)
            current->data = (*newData);

        current = current->next;
    }
}

void deleteNode(Node* head, int key);

void deleteNode(Node* head, int key)
{
    Node* current = head;
    Node* previous = current;

    while (current != NULL)
    {
        if (current->key == key)
        {
            previous->next = current->next;

            if (current == head)
                head = current->next;

            Destroy(&current->data);
            free(current);
            return;
        }

        // Go back one
        previous = current;
        current = current->next;
    }
}

Object* ToArray(List* list)
{
    int length = Size(list);

    Object *objArr = (Object*) malloc(length * sizeof(Object));

    int index = 0;
    Node* current = list->head;

    while (current != NULL)
    {
        objArr[index++] = current->data;
        current = current->next;
    }

    return objArr;
}

void RemoveObject(int key, List *list)
{
    deleteNode(list->head, key);
}

void DestroyList(List* list)
{
    Node* current = list->head;
    Node* next = current;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}
