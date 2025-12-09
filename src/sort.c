#include "sort.h"
#include "compare.h"
#include "list.h"

void bubble_sort(List* list, int (*compare_articles)(const Article*, const Article*), bool direction) {
    if (list->size <= 1) return;
    bool swapped;

    for (u_int i = 0; i < list->size - 1; i++) {
        swapped = false;
        for (u_int j = 0; j < list->size - 1 - i; j++) {
            Node* first = get_by_index(list, j);
            Node* second = get_by_index(list, j + 1);

            int result = compare_articles(&(first->data), &(second->data));

            if (direction) {
                if (result > 0) {
                    swap_near(list, first, second);
                    swapped = true;
                }
            }
            else {
                if (result < 0) {
                    swap_near(list, first, second);
                    swapped = true;
                }
            }


        }
        if (!swapped) break;
    }
}

