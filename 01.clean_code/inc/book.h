/**
 * @file book.h
 * @brief Interface for book entity and related operations.
 */

#ifndef BOOK_H_
#define BOOK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "slist.h"

/**
 * @brief Book structure definition
 */
typedef struct Book {
    int id;                     /**< Unique ID of the book */
    char title[100];            /**< Title of the book */
    char author[100];           /**< Author name */
    int quantity;               /**< Number of available copies */
} Book;

/**
 * @brief Create a new book instance
 */
Book* book_create(int id, const char* title, const char* author, int quantity);

/**
 * @brief Print a book object
 */
void book_print(void* data);

/**
 * @brief Free memory allocated for book
 */
void book_free(void* data);

/**
 * @brief Compare two books by ID
 */
int book_compare_by_id(void* a, void* b);

/**
 * @brief Compare two books by title lexicographically
 */
int book_compare_by_title_full(void* a, void* b);

/**
 * @brief Compare two books by title
 */
int book_compare_by_title(void* a, void* b);

#ifdef __cplusplus
}
#endif

#endif /* BOOK_H_ */
