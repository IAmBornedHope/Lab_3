#include "generation.h"
#include "article.h"
#include "list.h"
#include <stdlib.h>
#include <time.h>

static const char* article_names[] = {
    "Алгебраические структуры в нейросетях",
    "Этика машинного обучения",
    "БДЗ по дискретной математике",
    "Работа с памятью",
    "Безопасность Госуслуг",
    "Разоблачение мессенджера Мах",
    "Матанализ в информатике",
    "Псевдорандомные числа",
    "Построение графов",
    "Работа трехадресной ЭВМ"
};

static const char* author_surnames[] = {
    "Иванов", "Петров", "Сидоров", "Новиков", "Смирнов", "Александров",
    "Михайлов", "Беляцкий", "Мирчу", "Лисенков", "Шавалиев", "Булгакова",
    "Макаров", "Орлова", "Петропавловская", "Коврова", "Медведев", "Криворучко"
};

static const char* initials_list[] = {
    "А.Б.", "У.Е.", "В.Г.", "С.С.", "Г.Н.", "М.А.",
    "У.Ф.", "Я.Я.", "А.З.", "Л.А.", "А.Л.", "А.С.",
    "И.И.", "И.М.", "С.Т.", "Н.А.", "О.О.", "О.Ш." 
};

static const char* journals[] = {
    "Архивы ПМИ",
    "Галилео",
    "Разрушители мифов",
    "ЭВМ за ночь",
    "Матанализ для чайников",
    "Питон за час",
    "Все о Си"
    "В мире животных",
    "Умный журнал",
    "Журнал ИИ"
};

List* generate_articles(u_int count) {
    srand((u_int)time(NULL));
    List* list = initialize_list();
    if (!list) return NULL;

    u_int names_count = sizeof(article_names) / sizeof(article_names[0]);
    u_int surnames_count = sizeof(author_surnames) / sizeof(author_surnames[0]);
    u_int initials_count = sizeof(initials_list) / sizeof(initials_list[0]);
    u_int journals_count = sizeof(journals) / sizeof(journals[0]);

    for (u_int i = 0; i < count; i++) {
        Article note;

        snprintf(note.article_name, sizeof(note.article_name), "%s", article_names[rand() % names_count]);
        snprintf(note.author_surname, sizeof(note.author_surname), "%s", author_surnames[rand() % surnames_count]);
        snprintf(note.initials, sizeof(note.initials), "%s", initials_list[rand() % initials_count]);
        snprintf(note.journal_name, sizeof(note.journal_name), "%s", journals[rand() % journals_count]);

        note.year = 1900 + rand() % 126;
        note.book = 1 + rand() % 20;
        note.rinc = rand() % 2;
        note.pages = 1 + rand() % 500;
        note.citations = 1 + rand() % 100;

        push_end(list, &note);
    }
    return list;

        
}