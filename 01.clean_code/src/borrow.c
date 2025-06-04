/**
 * @file borrow.c
 * @brief Implementation of borrow logic for users and books
 */

#include <stdio.h>
#include <string.h>
#include "../inc/borrow.h"

void borrow_book_by_id(SListNode* book_list, SListNode* user_list, const char* user_name, int book_id, int amount) {
    User* user = (User*)slist_find(user_list, (void*)user_name, user_compare_by_name);
    Book key = {.id = book_id};
    Book* book = (Book*)slist_find(book_list, &key, book_compare_by_id);

    if (!user) {
        printf("User '%s' not found.\n", user_name);
        return;
    }

    if (!book) {
        printf("Book ID %d not found.\n", book_id);
        return;
    }

    if (book->quantity < amount) {
        printf("Book '%s' does not have enough copies to borrow (Available: %d).\n", book->title, book->quantity);
        return;
    }

    for (int i = 0; i < amount; ++i) {
        if (user_borrow_book(user, book)) {
            book->quantity--;
        }
    }
}
