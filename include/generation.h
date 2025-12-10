#pragma once
#include "article.h"
#include <stdio.h>
#include "list.h"

/**
 * @brief Функция для генерации случайных научных статей
 * 
 * @param count 
 * @return List* 
 */
List* generate_articles(u_int count);