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

/**
 * @brief Initializing a double linked list
 * 
 * @return List* 
 */
List* initialize_list();

/**
 * @brief Getting size of a double linked list
 * 
 * @param list 
 * @return u_int 
 */
u_int get_size(List* list);

/**
 * @brief Getting the node by index
 * 
 * @param list 
 * @param index 
 * @return Article* 
 */
Node* get_at(List* list, u_int index);
/**
 * @brief Getting the first node of the list
 * 
 * @param list 
 * @return Node* 
 */
Node* get_beginning(List* list);
/**
 * @brief Splitting a list into two parts by index
 * 
 * @param start 
 * @param middle 
 * @return Node* 
 */
Node* split_list(Node* start, u_int middle);
/**
 * @brief Getting the last node of the list
 * 
 * @param list 
 * @return Node* 
 */
Node* get_end(List* list);
/**
 * @brief Getting the next node from the pointer
 * 
 * @param list 
 * @param node 
 * @return Node* 
 */
Node* get_next(List* list, Node* node);
/**
 * @brief Getting the previous node from the pointer
 * 
 * @param list 
 * @param node 
 * @return Node* 
 */
Node* get_prev(List* list, Node* node);
/**
 * @brief Getting an article from a node by node index
 * 
 * @param list 
 * @param index 
 * @return Article* 
 */
Article* get_data(List* list, u_int index);
/**
 * @brief Adding a node to the top of the list
 * 
 * @param list 
 * @param data 
 */
void push_start(List* list, Article* data);
/**
 * @brief Adding a node to the end of the list
 * 
 * @param list 
 * @param data 
 */
void push_end(List* list, Article* data);
/**
 * @brief Adding an element to an arbitrary position in the list by index
 * 
 * @param list 
 * @param data 
 * @param index 
 */
void push_by_index(List* list, Article* data, u_int index);
/**
 * @brief Deleting the first item in the list
 * 
 * @param list 
 */
void pop_start(List* list);
/**
 * @brief Deleting the last item in the list
 * 
 * @param list 
 */
void pop_end(List* list);
/**
 * @brief Deleting any item in the list by index
 * 
 * @param list 
 * @param index 
 */
void pop_by_index(List* list, u_int index);

u_int max(u_int a, u_int b);
u_int min(u_int a, u_int b);

/**
 * @brief Exchanging two adjacent elements in a double linked list
 * 
 * @param list 
 * @param node1 
 * @param node2 
 */
void swap_near(List* list, Node* node1, Node* node2);
/**
 * @brief Exchanging two elements of a double linked list in general
 * 
 * @param list 
 * @param index1 
 * @param index2 
 */
void swap(List* list, u_int index1, u_int index2);
/**
 * @brief Converting an array to a structure
 * 
 * @param array 
 * @param size 
 * @return List* 
 */
List* array_to_list(Article* array, u_int size);
/**
 * @brief Converting a structure to an array
 * 
 * @param list 
 * @return Article* 
 */
Article* list_to_array(List* list);
/**
 * @brief Removing all items from the list
 * 
 */
void clear_list(List* list);
/**
 * @brief Clearing the memory allocated for the list
 * 
 * @param list 
 */
void free_list(List* list);