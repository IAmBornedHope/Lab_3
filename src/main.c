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

    u_int counter = 0;
    FILE* out_stream = stdout;
    FILE* timer = NULL;
    clock_t start, end;
    double time_used;
    
    List* list;
    Args* args = (Args*)malloc(sizeof(Args));
    if (parse_args(argc, argv, args) == -1) {
        return 0;
    }
    
    if (args->out_file[0] != '\0') {
        out_stream = fopen(args->out_file, "w");
    }
    
    if (args->help) counter++;
    if (args->generation) counter++;
    if (args->sort) counter++;
    if (args->print) counter++;

    if (counter > 1) {
        fprintf(stderr, "ERROR: FLAG COMBINATION");
        return 0;
    }
    
    if(args->help){
        print_help();
    }
    else if (args->generation && !args->input) {
        list = generate_list(args->num);
        print_csv(list, out_stream);
    }
    else if (args->sort) {
        if (args->input_file) list = input_csv(args->input_file);
        else list = input_csv(NULL);
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
        timer = fopen("TIMER.txt", "a");
        fprintf(timer, "%.3f\n", time_used);
        fclose(timer);

        print_csv(list, out_stream);
        printf("Runtime: %.3f с.", time_used);
    }

    else if (args->print) {
        if (args->input_file) list = input_csv(args->input_file);
        else list = input_csv(NULL);
        print_table(list, out_stream);
    }

    free_list(list);
    free(args);
    return 1;
}
