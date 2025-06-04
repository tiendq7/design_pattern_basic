/**
 * @file slist.c
 * @brief Implementation of simple singly linked list
 */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/slist.h"

SListNode* slist_append(SListNode* head, void* data) {
    SListNode* new_node = malloc(sizeof(SListNode));
    if (!new_node) return head;
    new_node->data = data;
    new_node->next = NULL;

    if (!head) return new_node;

    SListNode* curr = head;
    while (curr->next)
        curr = curr->next;
    curr->next = new_node;
    return head;
}

SListNode* slist_prepend(SListNode* head, void* data) {
    SListNode* new_node = malloc(sizeof(SListNode));
    if (!new_node) return head;
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

SListNode* slist_add_inorder(SListNode* head, void* data, SListCompareFn cmp) {
    SListNode* new_node = malloc(sizeof(SListNode));
    if (!new_node) return head;
    new_node->data = data;

    if (!head || cmp(data, head->data) < 0) {
        new_node->next = head;
        return new_node;
    }

    SListNode* curr = head;
    while (curr->next && cmp(curr->next->data, data) < 0)
        curr = curr->next;

    new_node->next = curr->next;
    curr->next = new_node;
    return head;
}

void* slist_find(SListNode* head, void* target, SListCompareFn cmp) {
    while (head) {
        if (cmp(head->data, target) == 0)
            return head->data;
        head = head->next;
    }
    return NULL;
}

void slist_traverse(SListNode* head, SListPrintFn print_fn) {
    while (head) {
        print_fn(head->data);
        head = head->next;
    }
}

int slist_length(SListNode* head) {
    int count = 0;
    while (head) {
        ++count;
        head = head->next;
    }
    return count;
}

SListNode* slist_delete(SListNode* head, void* target, SListCompareFn cmp, SListFreeFn free_fn) {
    SListNode* curr = head;
    SListNode* prev = NULL;

    while (curr) {
        if (cmp(curr->data, target) == 0) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            if (free_fn) free_fn(curr->data);
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

void slist_free(SListNode* head, SListFreeFn free_fn) {
    while (head) {
        SListNode* tmp = head;
        head = head->next;
        if (free_fn) free_fn(tmp->data);
        free(tmp);
    }
}
