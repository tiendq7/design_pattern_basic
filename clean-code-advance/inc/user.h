/**
 * @file user.h
 * @brief Interface for user management.
 */

#ifndef USER_H_
#define USER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "slist.h"
#include "book.h"
/**
 * @brief User structure
 */
typedef struct User {
    int id;                         /**< Unique ID of the user */
    char name[100];                /**< User name */
    SListNode* borrowed_books;     /**< List of borrowed books (Book*) */
} User;

/**
 * @brief Create a new user
 */
User* user_create(int id, const char* name);

/**
 * @brief Let a user borrow a copy of a book
 */
int user_borrow_book(User* user, Book* book);

/**
 * @brief Print user details
 */
void user_print(void* data);

/**
 * @brief Free memory for a user
 */
void user_free(void* data);

/**
 * @brief Compare user by ID
 */
int user_compare_by_id(void* a, void* b);

/**
 * @brief Compare user by name
 */
int user_compare_by_name(void* a, void* b);

#ifdef __cplusplus
}
#endif

#endif /* USER_H_ */
