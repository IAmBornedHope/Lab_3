#pragma once
#include "define.h"
#include "article.h"

// Узел двусвязного списка
typedef struct Node {
    Article data;
    struct Node* next;
    struct Node* prev;
} Node;

// ДС
typedef struct List {
    Node* head;
    Node* tail;
    u_int size;
} List;


List* Initialize_List();
int get_size(List* list);