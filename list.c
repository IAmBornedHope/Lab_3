#pragma once
#include "list.h"
#include <stdlib.h>


// Инициализация контейнера
List* Initialize_List() {
    List* list = malloc(sizeof(List));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Получение размера контейнера
u_int get_size(List* list) {
    return list->size;
}