/**
 * \file user.c
 * \brief Implementation of User-related functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/user.h"

User* user_create(int id, const char* name) {
    User* u = (User*)malloc(sizeof(User));
    if (!u) return NULL;
    u->id = id;
    strncpy(u->name, name, sizeof(u->name));
    u->name[sizeof(u->name) - 1] = '\0';
    u->borrowed_books = NULL;
    return u;
}

int user_borrow_book(User* user, Book* book) {
    if (!user || !book) return 0;

    // Create a shallow copy of the book with quantity = 1
    Book* book_copy = book_create(book->id, book->title, book->author, 1);
    if (!book_copy) return 0;

    user->borrowed_books = slist_append(user->borrowed_books, book_copy);
    return 1;
}

void user_print(void* data) {
    User* u = (User*)data;
    if (!u) return;
    printf("User ID: %d | Name: %s\n", u->id, u->name);
    printf("  Borrowed Books: \n");
    slist_traverse(u->borrowed_books, book_print);
}

void user_free(void* data) {
    User* u = (User*)data;
    if (!u) return;
    slist_free(u->borrowed_books, book_free);
    free(u);
}

int user_compare_by_id(void* a, void* b) {
    const User* ua = (const User*)a;
    const User* ub = (const User*)b;
    return ua->id - ub->id;
}

int user_compare_by_name(void* a, void* b) {
    const User* ua = (const User*)a;
    const char* name = (const char*)b;
    return strcmp(ua->name, name);
}
