#pragma once
#include "define.h"
#include "article.h"

typedef struct Node {
    Article data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    u_int size;
} List;


List* initialize_list();
u_int get_size(List* list);
Node* get_beginning(List* list);
Node* get_end(List* list);
Node* get_next(List* list, Node* node);
Node* get_prev(List* list, Node* node);
void push_start(List* list, Article* data);
void push_end(List* list, Article* data);