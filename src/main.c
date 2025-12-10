
#include "list.h"
#include "article.h"
#include "compare.h"
#include "define.h"
#include "inout.h"
#include "sort.h"
#include <stdio.h>
#include "generation.h"
#include <locale.h>
#include <windows.h>  




int main() {

    
    
    setlocale(LC_ALL, "C.UTF8");
    SetConsoleOutputCP(CP_UTF8);
    // List* list = initialize_list();
    
    // Article pub1 = {"Статья1", "123", "А. Е.", "В мире животных", 2023, 1, 1, 10, 5};
    // Article pub2 = {"Статья1", "1234567", "У. Г.", "ЦУЦУАЦ", 2024, 2, 0, 15, 10};
    // Article pub3 = {"Статья1", "12345", "Я. Ы.", "ЛЛЛЛЛЛ", 2022, 3, 1, 8, 3};


    // push_end(list, &pub1);
    // push_end(list, &pub2);
    // push_end(list, &pub3);
    List* list = generate_articles(30);

    print_csv(list, stdout);
    bubble_sort(list, compare_articles, 1);
    puts("---");
    print_csv(list, stdout);

    //FILE* output_file = fopen("test.csv", "w");
    //print_csv(list, stdout);
    //fclose(output_file);
    //printf("Данные записаны в файл.\n");
    free_list(list);


    
    return 0;
}