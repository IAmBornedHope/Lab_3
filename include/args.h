#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "define.h"

typedef struct _Args{
    int num;
    bool help;
    bool generation;
    bool input;
    bool output;
    bool print;
    bool sort;
    char* flag;
    char* out_file;
    char* input_file;
} Args;

/**
 * @brief Output of help menu for the user
 * 
 */

void print_help();
/**
 * @brief Processing command line arguments
 * 
 * @param argc 
 * @param argv 
 * @param args 
 * @return int 
 */
int parse_args(int argc, char* argv[], Args* args);
