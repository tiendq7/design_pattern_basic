/**
 * @file main.c
 * @brief Entry point for Library Management System using Clean Code and Linked List
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "user.h"
#include "borrow.h"
#include "slist.h"

int main(void) {
    SListNode* book_list = NULL;
    SListNode* user_list = NULL;

    // Add books (sorted by title)
    book_list = slist_add_inorder(book_list, book_create(1, "Clean Code", "Robert C. Martin", 3), book_compare_by_title_full);
    book_list = slist_add_inorder(book_list, book_create(2, "Design Patterns", "Erich Gamma", 2), book_compare_by_title_full);
    book_list = slist_add_inorder(book_list, book_create(3, "C Programming", "Dennis Ritchie", 1), book_compare_by_title_full);

    // Add users
    user_list = slist_append(user_list, user_create(1001, "Alice"));
    user_list = slist_append(user_list, user_create(1002, "Bob"));

    // Print books
    printf("\n Books available in the library:\n");
    slist_traverse(book_list, book_print);

    // Borrow books
    borrow_book_by_id(book_list, user_list, "Alice", 1, 2); // Alice borrows 2 copies of book ID 1
    borrow_book_by_id(book_list, user_list, "Bob", 3, 1);   // Bob borrows 1 copy of book ID 3
    borrow_book_by_id(book_list, user_list, "Alice", 2, 3); // Try to borrow more than available (should fail)

    // Print users and their borrowed books
    printf("\n List of users:\n");
    slist_traverse(user_list, user_print);

    // Print book list again after borrowing
    printf("\n Books after borrow:\n");
    slist_traverse(book_list, book_print);

    // Search for a book by title
    const char* search_title = "Clean Code";
    Book* found = (Book*)slist_find(book_list, (void*)search_title, book_compare_by_title);  // ✅ FIXED HERE
    printf("\n Search for book '%s':\n", search_title);
    if (found) {
        book_print(found);
    } else {
        printf("Book not found.\n");
    }

    // Cleanup
    slist_free(book_list, book_free);
    slist_free(user_list, user_free);
    return 0;
}
