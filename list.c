#pragma once
#include "list.h"
#include <stdlib.h>
#include <string.h>


List* initialize_list() {
    List* list = malloc(sizeof(List));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}


u_int get_size(List* list) {
    return list->size;
}


Node* get_by_index(List* list, u_int index) {
    if (index < 0 || index >= list->size) {
        return NULL;
    }

    Node* current = list->head;

    for (u_int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}


Node* get_beginning(List* list) {
    return list->head;
}


Node* get_end(List* list) {
    return list->tail;
}


Node* get_next(List* list, Node* node) {
    return node->next;
}


Node* get_prev(List* list, Node* node) {
    return node->prev;
}


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


void push_by_index(List* list, Article* data, u_int index) {
    if (index == 0) {
        push_start(list, data);
        return;
    }
    if (index == list->size) {
        push_end(list, data);
        return;
    }

    Node* current = list->head;
    for (u_int i = 0; i < index; i++) {
        current = current->next;
    }

    Node* new_article = malloc(sizeof(Node));
    if (!new_article) return NULL;
    new_article->data = *data;
    new_article->next = current;
    new_article->prev = current->prev;
    current->prev->next = new_article;
    current->prev = new_article;
    list->size++;

}


void pop_start(List* list) {
    if (!list->head) return;
    Node* tmp = list->head;
    list->head = list->head->next;

    if (list->head) {
        list->head->prev = NULL;
    }
    else {      
        list->tail = NULL;
    }

    free(tmp);
    list->size--;
}


void pop_end(List* list) {
    if (!list->tail) return;
    Node* tmp = list->tail;
    list->tail = list->tail->prev;

    if (list->tail) {
        list->tail->next = NULL;
    }
    else {
        list->head = NULL;
    }

    free(tmp);
    list->size--;
}


void pop_by_index(List* list, u_int index) {
    if (index < 0 || index >= list->size) return;
    if (index == 0) {
        pop_start(list);
        return;
    }
    if (index == list->size-1) {
        pop_end(list);
        return;
    }
    
    Node* current = list->head;
    for (u_int i = 0; i < index; i++) {
        current = current->next;
    }
    
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    list->size--;
}