#pragma once
#include "compare.h"
#include "article.h"
#include "list.h"
#include <stdlib.h>

/**
 * @brief Пузырьковая сортировка двусвязного списка с использованием функции-компаратора
 *
 * 
 * @param list 
 * @param compare_articles 
 * @param direction 1 - возрастание, 0 - убывание
 */
void bubble_sort(List* list, int (*compare_articles)(const Article*, const Article*), bool direction);

/**
 * @brief Разделение двусвязного списка на две части
 * 
 * @param start 
 * @param middle 
 * @return Node* 
 */
Node* split_list(Node* start, u_int middle);

/**
 * @brief Рекурсивная часть сортировки слиянием
 * 
 * @param head 
 * @param len 
 * @param compare_articles 
 * @param direction 
 * @return Node* 
 */

Node* merge_sort_recursion(Node* head, u_int len, int (*compare_articles)(const Article*, const Article*), bool direction);
/**
 * @brief Слияние двух списков
 * 
 * @param left 
 * @param right 
 * @param compare_articles 
 * @param direction 
 * @return Node* 
 */
Node* merge_lists(Node* left, Node* right, int (*compare_articles)(const Article*, const Article*), bool direction);
/**
 * @brief Сортировка двусвязного списка слиянием с использованием функции-компаратора
 * 
 * @param list 
 * @param compare_articles 
 * @param direction 1 - возрастание, 0 - убывание
 */
void merge_sort(List* list, int (*compare_articles)(const Article*, const Article*), bool direction);