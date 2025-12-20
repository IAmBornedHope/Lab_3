#include "args.h"

void print_help() {
    printf("%-30s %s\n", "-h --help", "Show this menu");
    printf("%-30s %s\n", "-g --generate=N", "Generate N random scientific articles");
    printf("%-30s %s\n", "-s --sort", "Sort the list");
    printf("%-30s %s\n", "-t --type (asc/desc/A/D)", "Select the sorting mode (asc by default)");
    printf("%-30s %s\n", "-o --out= data.csv", "Output to a file (stdout by default)");
    printf("%-30s %s\n", "-i --in= data.csv", "Input from file (stdin by default)");
    printf("%-30s %s\n", "-p --print", "Output in the form of a table");
}

int parse_args(int argc, char* argv[], Args* args) {
    args->help = false;
    args->generation = false;
    args->input = false;
    args->output = false;
    args->print = false;
    args->sort = false;
    args->flag = "asc";
    args->out_file = "";
    args->input_file = NULL;
    args->num = 0;
    if (argc == 1) {
        args->help = true;
        return 1;
    }

    for (u_int i = 1; i < argc; ++i) {
        char* arg = argv[i];

        if (strcmp(arg, "-") == 0 || strcmp(arg, "--") == 0) {
            fprintf(stderr, "INVALID FLAG\n");
            return -1;
        }
        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            args->help = true;
        }
        else if (strcmp(arg, "-p") == 0 || strcmp(arg, "--print") == 0) {
            args->print = true; 
        }
        else if (strcmp(arg, "-s") == 0 || strcmp(arg, "--sort") == 0) {
            args->sort = true;
        }
        else if (strncmp(arg, "-o", 2) == 0 || strncmp(arg, "--out", 5) == 0) {
            args->output = true;
            char* value = NULL;
            if (strncmp(arg, "--out=", 6) == 0) {
                value = arg + 6;
            }
            else if (strncmp(arg, "-o", 2) == 0 && i + 1 < argc ) {
                value = argv[++i];
            }
            else {
                fprintf(stderr, "INVALID FLAG\n");
                args->output = false;
                args->sort = false;
                return 0;
            }
            args->out_file = value;
        }
        else if (strncmp(arg, "-t", 2) == 0 || strncmp(arg, "--type", 6) == 0) {
            char* value = NULL;
            if (strncmp(arg, "--type=", 7) == 0) {
                value = arg + 7;
            }
            else if (strncmp(arg, "-t", 2) == 0 && i + 1 < argc ) {
                value = argv[++i];
            }
            else {
                fprintf(stderr, "INVALID FLAG\n");
                args->sort = false;
                return 0;
            }
            args->flag = strdup(value);
        }

        else if (strncmp(arg, "-i", 2) == 0 || strncmp(arg, "--in", 4) == 0) {
            args->input = true;
            char* value = NULL;
            if (strncmp(arg, "--in=", 5) == 0) {
                value = arg + 5;
            }
            else if (strncmp(arg, "-i", 2) == 0 && i + 1 < argc) {
                value = argv[++i];
            }
            else {
                fprintf(stderr, "INVALID FLAG\n");
                args->sort = false;
                return 0;
            }
            args->input_file = strdup(value);


        }
        else if (strncmp(arg, "-g", 2) == 0 || strncmp(arg, "--generate", 10) == 0) {
            args->generation = true;
            char* value = NULL;
            if (strncmp(arg, "--generate=", 11) == 0) {
                value = arg + 11;
            }
            else if (strncmp(arg, "-g", 2) == 0 && i + 1 < argc) {
                value = argv[++i];
            }
            else {
            fprintf(stderr, "INVALID FLAG\n");
            return 0;
            }
            args->num = atoi(value);
            if (args->num < 0) {
                fprintf(stderr, "INCORRECT N\n");
                args->generation = false;
                return 0;
            }
    }
}
}
