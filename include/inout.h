#pragma once
#include "list.h"
#include "compare.h"
#include "define.h"
#include <stdio.h>

/**
 * @brief Function for displaying a list in CSV format
 * 
 * @param list 
 * @param output_file 
 */
void print_csv(List* list, FILE* output_file);
/**
 * @brief Function for displaying a list in a fixed-width table format
 * 
 * @param list 
 * @param output_file 
 */
void print_table(List* list, FILE* output_file);
/**
 * @brief Input of scientific publications in CSV format from a specified file or from an input stream
 * 
 * @param input_file 
 * @return List* 
 */
List* input_csv(char* input_file);
