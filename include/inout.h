#pragma once
#include "list.h"
#include "article.h"
#include "compare.h"
#include "define.h"
#include "inout.h"
#include "sort.h"
#include <stdio.h>

/**
 * @brief Функция для вывода списка в CSV-формате
 * 
 * @param list 
 * @param output_file 
 */
void print_csv(List* list, FILE* output_file);
void print_table(List* list, FILE* output_file);
List* input_csv(const char* input_file);
