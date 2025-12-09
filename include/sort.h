#pragma once
#include "compare.h"
#include "article.h"
#include "list.h"
#include <stdlib.h>

/**
 * @brief Пузырьковая сортировка двусвязного списка с использованием функции-компаратора
 * 
 * @param list 
 * @param compare_articles 
 */
void bubble_sort(List* list, int (*compare_articles)(const Article*, const Article*), bool direction);