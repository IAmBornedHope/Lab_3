#include "inout.h"
#include "define.h"
#include "article.h"
#include <stdio.h>
#include <string.h>

void print_csv(List* list, FILE* output_file) {
    Node* current = list->head;
    while (current) {
        fprintf(output_file, "%s,%s,%s,%s,%d,%d,%d,%d,%d\n",
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