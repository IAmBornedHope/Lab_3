#include "inout.h"
#include "define.h"
#include "article.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void print_csv(List* list, FILE* output_file) {
    Node* current = list->head;
    while (current) {
        fprintf(output_file, "%s,%s,%s,%s,%u,%u,%d,%u,%u\n",
            current->data.article_name,
            current->data.author_surname,
            current->data.initials,
            current->data.journal_name,
            current->data.year,
            current->data.book,
            current->data.rinc,
            current->data.pages,
            current->data.citations);
        current = current->next;
    }
}

List* input_csv(const char* filename) {
    FILE* source = NULL;
    char buf[1024];
    List* list = initialize_list();
    if (!list) return NULL;


    if (filename) {
        source = fopen(filename, "r");
        if (!source) {
            puts("Не удалось открыть файл");
            free_list(list);
            return NULL;
        }
    }
    else {
        source = stdin;
    }

    fgets(buf, sizeof(buf), source);

    while (fgets(buf, sizeof(buf), source)) {
        Article note;
        u_int rinc_digit;

        if (buf[0] == '\n') break;
         
        int result = sscanf(buf, "%255[^,],%127[^,],%24[^,],%255[^,],%u,%u,%u,%u,%u",
            note.article_name, note.author_surname, note.initials, note.journal_name,
            &note.year, &note.book, &rinc_digit, &note.pages, &note.citations);

        if (result != 9) {
            puts("Неверное количество аргументов. Данная строка будет пропущена.");
            continue;
        }

        if (note.year < 1000 || note.year > 9999) {
            puts("Год не может быть не четырехзначным. Данная строка будет пропущена.");
            continue;
        }


        if (rinc_digit == 0) note.rinc = 0;
        else note.rinc = 1;


        push_end(list, &note);
    }
    if (filename) fclose(source);
    return list;
}




