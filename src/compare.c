#include "compare.h"
#include <string.h>
#include <stdio.h>

int compare_articles(const Article* a, const Article* b) {
    int flag = 0;

    flag = strcmp(a->article_name, b->article_name);
    if (flag != 0) return flag;
    
    flag = strcmp(a->author_surname, b->author_surname);
    if (flag != 0) return flag;
    
    flag = strcmp(a->initials, b->initials);
    if (flag != 0) return flag;
    
    flag = strcmp(a->journal_name, b->journal_name);
    if (flag != 0) return flag;

    if (a->year > b->year) flag = 1;
    else if (a->year < b->year) flag = -1;
    else flag = 0;
    if (flag != 0) return flag;

    if (a->book > b->book) flag = 1;
    else if (a->book < b->book) flag = -1;
    else flag = 0;
    if (flag != 0) return flag;

    if (a->rinc > b->rinc) flag = 1;
    else if (a->rinc < b->rinc) flag = -1;
    else flag = 0;
    if (flag != 0) return flag;

    if (a->citations > b->citations) flag = 1;
    else if (a->citations < b->citations) flag = -1;
    else flag = 0;
    if (flag != 0) return flag;

    if (a->pages > b->pages) flag = 1;
    else if (a->pages < b->pages) flag = -1;
    else flag = 0;
    if (flag != 0) return flag;

    return flag;
}