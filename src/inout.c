#include "inout.h"
#include "define.h"
#include "article.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void print_csv(List* list, FILE* output_file) {
    fprintf(output_file, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n", "ARTICLE NAME", "AUTHOR_SURNAME",
    "AUTHOR_INITIALS", "JOURNAL_NAME", "YEAR", "BOOK NO", "RINC", "PAGES", "CITATIONS");
    Node* current = list->head;
    while (current) {
        fprintf(output_file, "%s,%s,%s,%s,%u,%u,%s,%u,%u\n",
            current->data.article_name,
            current->data.author_surname,
            current->data.initials,
            current->data.journal_name,
            current->data.year,
            current->data.book,
            current->data.rinc  ? "YES" : "NO",
            current->data.pages,
            current->data.citations);
        current = current->next;
    }
}

void print_table(List* list, FILE* output_file) {
    fprintf(output_file, "%-23s  %-16s %-15s %-20s %-12s %-12s %-12s %-12s %-16s\n",
            "|Name|", "|Author|", "|Initials|", "|Journal|", "|Year|", "|Book No|", "|RINC|", "|Pages|", "|Citations|");
    fprintf(output_file, "%s%s\n",
            "---------------------------------------------------------------------",
            "-------------------------------------------------------------------------------\n");

    Node* current = list->head;
    while (current) {
        fprintf(output_file, "%-20.20s...  %-15.15s   %-13.13s  %-19.19s  %-12d   %-10d  %-12.12s  %-13d%-16d\n",
                current->data.article_name,
                current->data.author_surname,
                current->data.initials,
                current->data.journal_name,
                current->data.year,
                current->data.book,
                current->data.rinc ? "YES" : "NO",
                current->data.pages,
                current->data.citations);
        current = current->next;
        fprintf(output_file, "%s%s\n",
            "---------------------------------------------------------------------",
            "----------------------------------------------------------------------------\n");
        }
}

List* input_csv(char* input_file) {
    FILE* source = NULL;
    char buf[1024];
    List* list = initialize_list();
    if (!list) return NULL;


    if (input_file) {
        source = fopen(input_file, "r");
        if (!source) {
            puts("Не удалось открыть файл");
            free_list(list);
            return NULL;
        }
    }
    else {
        source = stdin;
    }

    while (fgets(buf, sizeof(buf), source)) {
        Article note;
        u_int rinc_digit;

        if (buf[0] == '\n') break;
         
        int result = sscanf(buf, "%255[^,],%127[^,],%24[^,],%255[^,],%u,%u,%u,%u,%u",
            note.article_name, note.author_surname, note.initials, note.journal_name,
            &note.year, &note.book, &rinc_digit, &note.pages, &note.citations);

        if (note.year < 1000 || note.year > 2025) {
            puts("Введен недопустимый год. Данная строка будет пропущена.");
            continue;
        }


        if (rinc_digit == 0) note.rinc = 0;
        else note.rinc = 1;


        push_end(list, &note);
    }
    if (input_file) fclose(source);
    return list;
}




