#include "sort.h"
#include "compare.h"
#include "list.h"
typedef int (*Comparator)(const Article*, const Article*);

void bubble_sort(List* list, Comparator comp, bool direction) {
    if (list->size <= 1) return;
    bool swapped;

    for (u_int i = 0; i < list->size - 1; i++) {
        swapped = false;
        for (u_int j = 0; j < list->size - 1 - i; j++) {
            int result = comp(get_data(list, j), get_data(list, j + 1));

            if (direction) {
                if (result > 0) {
                    swap_near(list, get_at(list, j), get_at(list, j + 1));
                    swapped = true;
                }
            }
            else {
                if (result < 0) {
                    swap_near(list, get_at(list, j), get_at(list, j + 1));
                    swapped = true;
                }
            }
        }
        if (!swapped) break;
    }
}

Node* merge_lists(Node* left, Node* right, Comparator comp, bool direction) {
    Node empty_node;
    Node* tail = &empty_node;
    empty_node.next = NULL;

    while (left && right) {
        int cmp = comp(&(left->data), &(right->data));
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

Node* merge_sort_recursion(Node* head, u_int len, Comparator comp, bool direction) {
    if (len <= 1) return head;

    u_int middle = len / 2;
    Node* second_half = split_list(head, middle);
    Node* left = merge_sort_recursion(head, middle, comp, direction);
    Node* right = merge_sort_recursion(second_half, len - middle, comp, direction);
    return merge_lists(left, right, comp, direction);
}

void merge_sort(List* list, Comparator comp, bool direction) {
    if (list->size <= 1) return;
    list->head = merge_sort_recursion(list->head, list->size, comp, direction);
}