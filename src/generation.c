#include "generation.h"
#include "article.h"
#include "list.h"
#include <stdlib.h>
#include <time.h>

static const char* article_names[] = {
    "Algebraic Structures in Neural Networks",
    "Ethics of Machine Learning",
    "Homework on Discrete Mathematics",
    "Working with Memory",
    "Security of Gosuslugi (State Services)",
    "Exposing the Makh Messenger",
    "Mathematical Analysis in Computer Science",
    "Pseudorandom Numbers",
    "Graph Construction",
    "Operation of a Three-Address Computer"
};

static const char* author_surnames[] = {
    "Ivanov", "Petrov", "Sidorov", "Novikov", "Smirnov", "Aleksandrov",
    "Mikhailov", "Belyatsky", "Mirchu", "Lisenkov", "Shavaliyev", "Bulgakova",
    "Makarov", "Orlova", "Petropavlovskaya", "Kovrova", "Medvedev", "Krivoruchko"
};

static const char* initials_list[] = {
    "A.B.", "U.E.", "V.G.", "S.S.", "G.N.", "M.A.",
    "U.F.", "Y.Y.", "A.Z.", "L.A.", "A.L.", "A.S.",
    "I.I.", "I.M.", "S.T.", "N.A.", "O.O.", "O.Sh."
};

static const char* journals[] = {
    "Archives of PMI",
    "Galileo",
    "MythBusters",
    "Computers Overnight",
    "Calculus for Dummies",
    "Python in an Hour",
    "All About C",
    "In the World of Animals",
    "Smart Journal",
    "AI Journal"
};

Article generate_article() {
    Article note;

    u_int names_count = sizeof(article_names) / sizeof(article_names[0]);
    u_int surnames_count = sizeof(author_surnames) / sizeof(author_surnames[0]);
    u_int initials_count = sizeof(initials_list) / sizeof(initials_list[0]);
    u_int journals_count = sizeof(journals) / sizeof(journals[0]);

    snprintf(note.article_name, sizeof(note.article_name), "%s", article_names[rand() % names_count]);
    snprintf(note.author_surname, sizeof(note.author_surname), "%s", author_surnames[rand() % surnames_count]);
    snprintf(note.initials, sizeof(note.initials), "%s", initials_list[rand() % initials_count]);
    snprintf(note.journal_name, sizeof(note.journal_name), "%s", journals[rand() % journals_count]);

    note.year = 1900 + rand() % 126;
    note.book = 1 + rand() % 20;
    note.rinc = rand() % 2;
    note.pages = 1 + rand() % 500;
    note.citations = 1 + rand() % 100;

    return note;
}
List* generate_list(u_int count) {
    srand((u_int)time(NULL));
    List* list = initialize_list();
    if (!list) return NULL;
    for (u_int i = 0; i < count; i++) {
        Article note = generate_article();
        push_end(list, &note);
    }
    return list;
}