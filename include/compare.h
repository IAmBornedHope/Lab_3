#pragma once
#include "article.h"

/**
 * @brief Функция для сравнения двух статей. Возвращает -1, 0 или 1
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int compare_articles(const Article* a, const Article* b);