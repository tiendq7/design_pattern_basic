/**
 * @file book.c
 * @brief Implementation of book functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/book.h"

Book* book_create(int id, const char* title, const char* author, int quantity) {
    Book* b = (Book*)malloc(sizeof(Book));
    if (!b) return NULL;
    b->id = id;
    strncpy(b->title, title, sizeof(b->title));
    strncpy(b->author, author, sizeof(b->author));
    b->title[sizeof(b->title) - 1] = '\0';
    b->author[sizeof(b->author) - 1] = '\0';
    b->quantity = quantity;
    return b;
}

void book_print(void* data) {
    Book* b = (Book*)data;
    if (b)
        printf("[ID: %d] '%s' by %s (Available: %d)\n",
               b->id, b->title, b->author, b->quantity);
}

void book_free(void* data) {
    free(data);
}

int book_compare_by_id(void* a, void* b) {
    const Book* ba = (const Book*)a;
    const Book* bb = (const Book*)b;
    return (ba->id - bb->id);
}

int book_compare_by_title_full(void* a, void* b) {
    const Book* ba = (const Book*)a;
    const Book* bb = (const Book*)b;
    return strcmp(ba->title, bb->title);
}
int book_compare_by_title(void* a, void* b) {
    const Book* book = (const Book*)a;
    const char* title = (const char*)b;
    return strcmp(book->title, title);
}
