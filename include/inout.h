#pragma once
#include "list.h"
#include "compare.h"
#include "define.h"
#include <stdio.h>

/**
 * @brief Функция для вывода списка в CSV-формате
 * 
 * @param list 
 * @param output_file 
 */
void print_csv(List* list, FILE* output_file);
/**
 * @brief Функция для вывода списка в формате таблицы с фиксированной шириной
 * 
 * @param list 
 * @param output_file 
 */
void print_table(List* list, FILE* output_file);
/**
 * @brief Ввод научных публикаций в CSV формате из указанного файла или с потока ввода
 * 
 * @param input_file 
 * @return List* 
 */
List* input_csv(const char* input_file);
