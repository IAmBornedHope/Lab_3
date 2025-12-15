#include "list.h"
#include "compare.h"
#include "define.h"
#include "inout.h"
#include "generation.h"
#include "sort.h"
#include "args.h"
#include <locale.h>
#include <windows.h>  
#include <time.h>



int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "C.UTF8");
    SetConsoleOutputCP(CP_UTF8);
    clock_t start, end;
    double time_used;
    
    List* list;
    Args* args = (Args*)malloc(sizeof(Args));
    parse_args(argc, argv, args);
    FILE* out_stream = stdout;
    if (args->out_file[0] != '\0') {
        out_stream = fopen(args->out_file, "w");
    }

    if(args->help){
        print_help();
    }
    else{
        if(args->generation) {
            list = generate_articles(args->num);
        }
        else if(args->input_file){
            list = input_csv(args->input_file);
        }
        else {
            list = input_csv(NULL);
        }

        if(args->sort){
            start = clock();
            if(strcmp(args->flag, "desc") == 0 || strcmp(args->flag, "D") == 0) {
                bubble_sort(list, compare_articles, 0);
                //merge_sort(list, compare_articles, 0);
            }
            else{
                bubble_sort(list, compare_articles, 1);
                //merge_sort(list, compare_articles, 1);
            }
            end = clock();
            time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        }

        if(args->output) {
            print_csv(list, out_stream);
        }
        else if(args->print) {
            print_table(list, out_stream);
        }
        else {
            print_table(list, out_stream);
        }
    }
    printf("Время работы: %.3f с.", time_used);
    free_list(list);
    free(args);
}
