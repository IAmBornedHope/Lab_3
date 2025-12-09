#include "list.h"
#include <stdlib.h>
#include <string.h>


List* initialize_list() {
    List* list = malloc(sizeof(List));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}


u_int get_size(List* list) {
    return list->size;
}


Node* get_by_index(List* list, u_int index) {
    if (index >= list->size) {
        return NULL;
    }

    if (index <= (list->size / 2)) {
        Node* current = list->head;

        for (u_int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }
    else {
        Node* current = list->tail;
        for (u_int i = list->size - 1; i > index; i--) {
            current = current->prev;
        }
        return current;
    }
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

Article* get_data(List* list, u_int index) {
    Node* node = get_by_index(list, index);
    if (node) {
        return &(node->data);
    }
    else return NULL;
}


void push_start(List* list, Article* data) {
    Node* new_article = malloc(sizeof(Node));
    if (!new_article) return;
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
    if (!new_article) return;
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
    if (!new_article) return;
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
    if (index >= list->size) return;
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

u_int max(u_int a, u_int b) {
    if (a > b) return a;
    else return b;
}

u_int min(u_int a, u_int b) {
    if (a < b) return a;
    else return b;
}

void swap_near(List* list, Node* node1, Node* node2) {
        if (node1->prev) {
            node1->prev->next = node2;
        }
        else {
            list->head = node2;
        }

        if (node2->next) {
            node2->next->prev = node1;
        }
        else {
            list->tail = node1;
        }

        node1->next = node2->next;
        node2->prev = node1->prev;
        node2->next = node1;
        node1->prev = node2;
}
void swap(List* list, u_int index1, u_int index2) {
    if (index1 >= list->size || index2 >= list->size || index1 == index2) return;

    Node* node1 = get_by_index(list, min(index1, index2));
    Node* node2 = get_by_index(list, max(index1, index2));
    if (node1->next == node2) {
        swap_near(list, node1, node2);
        return;
    }

    node1->next->prev = node2;
    node2->prev->next = node1;

    if (node1->prev) {
        node1->prev->next = node2;
    }
    else {
        list->head = node2;
    }

    if (node2->next) {
        node2->next->prev = node1;
    }
    else {
        list->tail = node1;
    }


    Node* tmp1 = node1->next;
    Node* tmp2 = node1->prev;

    node1->next = node2->next;
    node1->prev = node2->prev;
    node2->next = tmp1;
    node2->prev = tmp2;
}

List* array_to_list(Article* array, u_int size) {
    List* list = initialize_list();
    for (u_int i = 0; i < size; i++) {
        push_end(list, &array[i]);
    }
    return list;
}

Article* list_to_array(List* list) {
    Article* array = malloc(list->size * sizeof(Article));
    if (!array) return NULL;

    Node* current = list->head;
    for (u_int i = 0; i < list->size; i++) {
        array[i] = current->data;
        current = current->next;
    }
    return array;
}

void clear_list(List* list) {
    while (list->head) {
        Node* tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }
    list->tail = NULL;
    list->size = 0;
}

void free_list(List* list) {
    clear_list(list);
    free(list);
}