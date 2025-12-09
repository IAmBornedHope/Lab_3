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
 * @brief Инициализация двусвязного списка
 * 
 * @return List* 
 */
List* initialize_list();

/**
 * @brief Получение размеров двусвязного списка
 * 
 * @param list 
 * @return u_int 
 */
u_int get_size(List* list);

/**
 * @brief Получение первого элемента по индексу
 * 
 * @param list 
 * @param index 
 * @return Article* 
 */
Node* get_by_index(List* list, u_int index);
/**
 * @brief Получение первого узла списка
 * 
 * @param list 
 * @return Node* 
 */
Node* get_beginning(List* list);
/**
 * @brief Получение последнего узла списка
 * 
 * @param list 
 * @return Node* 
 */
Node* get_end(List* list);
/**
 * @brief Получение следующего узла от указателя
 * 
 * @param list 
 * @param node 
 * @return Node* 
 */
Node* get_next(List* list, Node* node);
/**
 * @brief Получение предыдущего узла от указателя
 * 
 * @param list 
 * @param node 
 * @return Node* 
 */
Node* get_prev(List* list, Node* node);
/**
 * @brief Получение статьи из узла по индексу узла
 * 
 * @param list 
 * @param index 
 * @return Article* 
 */
Article* get_data(List* list, u_int index);
/**
 * @brief Добавление узла в начало списка
 * 
 * @param list 
 * @param data 
 */
void push_start(List* list, Article* data);
/**
 * @brief Добавление узла в конец списка
 * 
 * @param list 
 * @param data 
 */
void push_end(List* list, Article* data);
/**
 * @brief Добавление элемента в произвольное место списка по индексу
 * 
 * @param list 
 * @param data 
 * @param index 
 */
void push_by_index(List* list, Article* data, u_int index);
/**
 * @brief Удаление первого элемента списка
 * 
 * @param list 
 */
void pop_start(List* list);
/**
 * @brief Удаление последнего элемента списка
 * 
 * @param list 
 */
void pop_end(List* list);
/**
 * @brief Удаление произвольного элемента списка по индексу
 * 
 * @param list 
 * @param index 
 */
void pop_by_index(List* list, u_int index);

u_int max(u_int a, u_int b);
u_int min(u_int a, u_int b);

/**
 * @brief Обмен двух соседних элементов двусвязного списка
 * 
 * @param list 
 * @param node1 
 * @param node2 
 */
void swap_near(List* list, Node* node1, Node* node2);
/**
 * @brief Обмен двух элементов двусвязного списка в общем случае
 * 
 * @param list 
 * @param index1 
 * @param index2 
 */
void swap(List* list, u_int index1, u_int index2);
/**
 * @brief Преобразование массива в структуру
 * 
 * @param array 
 * @param size 
 * @return List* 
 */
List* array_to_list(Article* array, u_int size);
/**
 * @brief Преобразование структуры в массив
 * 
 * @param list 
 * @return Article* 
 */
Article* list_to_array(List* list);
/**
 * @brief Удаление всех элементов из списка
 * 
 */
void clear_list(List* list);
/**
 * @brief Очистка выделенной под список памяти
 * 
 * @param list 
 */
void free_list(List* list);