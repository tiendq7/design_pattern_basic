/**
 * @file borrow.h
 * @brief Borrowing operations between users and books
 */

#ifndef BORROW_H_
#define BORROW_H_

#include "user.h"
#include "book.h"

/**
 * @brief Allow user to borrow a book by its ID and quantity
 *
 * @param book_list List of books
 * @param user_list List of users
 * @param user_name Name of the user
 * @param book_id   ID of the book to borrow
 * @param amount    Number of copies to borrow
 */
void borrow_book_by_id(SListNode* book_list, SListNode* user_list, const char* user_name, int book_id, int amount);

#endif // BORROW_H_
