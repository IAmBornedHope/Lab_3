#pragma once
#include "list.h"
#include <stdlib.h>

/**
 * @brief Инициализация двусвязного списка
 * 
 * @return List* 
 */
List* initialize_list() {
    List* list = malloc(sizeof(List));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/**
 * @brief Получение количества статей в списке
 * 
 * @param list 
 * @return u_int 
 */
u_int get_size(List* list) {
    return list->size;
}

/**
 * @brief Получение адреса элемента списка по индексу
 * 
 * @param list 
 * @param index 
 * @return Article* 
 */
Article* get_by_index(List* list, u_int index) {
    if (index < 0 || index >= list->size) {
        return NULL;
    }

    Node* current = list->head;

    for (u_int i = 0; i < index; i++) {
        current = current->next;
    }
    return &(current->data);
}


/**
 * @brief Получение первого узла списка
 * 
 * @param list 
 * @return Node* 
 */
Node* get_beginning(List* list) {
    return list->head;
}

/**
 * @brief Получение последнего узла списка
 * 
 * @param list 
 * @return Node* 
 */
Node* get_end(List* list) {
    return list->tail;
}

/**
 * @brief Получение следующего узла списка после заданного указателя
 * 
 * @param list 
 * @param node 
 * @return Node* 
 */
Node* get_next(List* list, Node* node) {
    return node->next;
}

/**
 * @brief Получение предыдущего узла списка перед заданным указателем
 * 
 * @param list 
 * @param node 
 * @return Node* 
 */
Node* get_prev(List* list, Node* node) {
    return node->prev;
}


/**
 * @brief Добавление элемента в начало списка
 * 
 * @param list 
 * @param data 
 */
void push_start(List* list, Article* data) {
    Node* new_article = malloc(sizeof(Node));
    if (!new_article) return NULL;
    new_article->data = *data;
    new_article->next = list->head;
    new_article->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = new_article;
    }
    else {
        list->tail = new_article;
    }
    list->head = new_article;
    list->size++;
}

/**
 * @brief Добавление элемента в конец списка
 * 
 * @param list 
 * @param data 
 */
void push_end(List* list, Article* data) {
    Node* new_article = malloc(sizeof(Node));
    if (!new_article) return NULL;
    new_article->data = *data;
    new_article->next = NULL;
    new_article->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = new_article;
    }
    else {
        list->head = new_article;
    }
    list->tail = new_article;
    list->size++;
}

//
// void push_by_index(List* list, Article* data, u_int index) {
//     if (index == 0) {
//         push_start(list, data);
//         return;
//     }
//     if (index == list->size) {
//         push_end(list, data);
//         return;
//     }



// }