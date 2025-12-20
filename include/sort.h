#pragma once
#include "compare.h"
#include "article.h"
#include "list.h"
#include <stdlib.h>

/**
 * @brief Bubble sort of a double linked list using a comparator function
 *
 * 
 * @param list 
 * @param compare_articles 
 * @param direction 1 - increasing, 0 - decreasing
 */
void bubble_sort(List* list, int (*compare_articles)(const Article*, const Article*), bool direction);

/**
 * @brief The recursive part of merge sort
 * 
 * @param head 
 * @param len 
 * @param compare_articles 
 * @param direction 
 * @return Node* 
 */

Node* merge_sort_recursion(Node* head, u_int len, int (*compare_articles)(const Article*, const Article*), bool direction);
/**
 * @brief Merging two lists
 * 
 * @param left 
 * @param right 
 * @param compare_articles 
 * @param direction 
 * @return Node* 
 */
Node* merge_lists(Node* left, Node* right, int (*compare_articles)(const Article*, const Article*), bool direction);
/**
 * @brief Sorting a double linked list by merging using a comparator function
 * 
 * @param list 
 * @param compare_articles 
 * @param direction 1 - increasing, 0 - decreasing
 */
void merge_sort(List* list, int (*compare_articles)(const Article*, const Article*), bool direction);