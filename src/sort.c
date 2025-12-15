#include "sort.h"
#include "compare.h"
#include "list.h"

// void bubble_sort(List* list, int (*compare_articles)(const Article*, const Article*), bool direction) {
//     if (list->size <= 1) return;
//     bool swapped;

//     for (u_int i = 0; i < list->size - 1; i++) {
//         swapped = false;
//         for (u_int j = 0; j < list->size - 1 - i; j++) {
//             Node* first = get_by_index(list, j);
//             Node* second = get_by_index(list, j + 1);

//             int result = compare_articles(&(first->data), &(second->data));

//             if (direction) {
//                 if (result > 0) {
//                     swap_near(list, first, second);
//                     swapped = true;
//                 }
//             }
//             else {
//                 if (result < 0) {
//                     swap_near(list, first, second);
//                     swapped = true;
//                 }
//             }


//         }
//         if (!swapped) break;
//     }
// }

void bubble_sort(List* list, int (*compare_articles)(const Article*, const Article*), bool direction) {
    if (list->size <= 1) return;
    bool swapped;

    for (u_int i = 0; i < list->size - 1; i++) {
        swapped = false;
        for (u_int j = 0; j < list->size - 1 - i; j++) {
            int result = compare_articles(get_data(list, j), get_data(list, j + 1));

            if (direction) {
                if (result > 0) {
                    swap_near(list, get_by_index(list, j), get_by_index(list, j + 1));
                    swapped = true;
                }
            }
            else {
                if (result < 0) {
                    swap_near(list, get_by_index(list, j), get_by_index(list, j + 1));
                    swapped = true;
                }
            }
        }
        if (!swapped) break;
    }
}



/*
Работа над сортировкой начата до комментария о протаскивании Node в сортировку
Реализовать слияние без этого скорее всего уже не успелось бы, так что есть, что есть :((( 
*/
Node* split_list(Node* start, u_int middle) {
    for (u_int i = 0; i < middle - 1; i++) {
        start = start->next;
    }
    Node* second = start->next;
    second->prev = NULL;
    start->next = NULL;
    return second;
}

Node* merge_lists(Node* left, Node* right, int (*compare_articles)(const Article*, const Article*), bool direction) {
    Node empty_node;
    Node* tail = &empty_node;
    empty_node.next = NULL;

    while (left && right) {
        int cmp = compare_articles(&(left->data), &(right->data));
        if (direction) {
            if (cmp <= 0) {
                tail->next = left;
                left->prev = tail;
                left = left->next;
            }
            else {
                tail->next = right;
                right->prev = tail;
                right = right->next;
            }
        }
        else {
            if (cmp >= 0) {
                tail->next = left;
                left->prev = tail;
                left = left->next;
            }
            else {
                tail->next = right;
                right->prev = tail;
                right = right->next;
            }
        }
        tail = tail->next;
    }
    if (left) {
        tail->next = left;
        left->prev = tail;
    }
    else if (right) {
        tail->next = right;
        right->prev = tail;
    }

    Node* result = empty_node.next;
    result->prev = NULL;
    return result;
}

Node* merge_sort_recursion(Node* head, u_int len, int (*compare_articles)(const Article*, const Article*), bool direction) {
    if (len <= 1) return head;

    u_int middle = len / 2;
    Node* second_half = split_list(head, middle);
    Node* left = merge_sort_recursion(head, middle, compare_articles, direction);
    Node* right = merge_sort_recursion(second_half, len - middle, compare_articles, direction);
    return merge_lists(left, right, compare_articles, direction);
}

void merge_sort(List* list, int (*compare_articles)(const Article*, const Article*), bool direction) {
    if (list->size <= 1) return;
    list->head = merge_sort_recursion(list->head, list->size, compare_articles, direction);
}