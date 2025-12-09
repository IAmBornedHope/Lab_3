#pragma once
#include "define.h"
#include "stdbool.h"

typedef struct {
    char article_name[256];
    char author_surname[128];
    char initials[8];
    char journal_name[256];
    u_int year;
    u_int book;
    bool rinc;
    u_int pages;
    u_int citations;
} Article;