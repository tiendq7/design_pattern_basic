/**
 * \\file slist.h
 * \\brief Singly linked list generic header for reusable data structures
 */

#ifndef SLIST_H_
#define SLIST_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdlib.h>
#include <stdio.h>

/**
 * \\brief Linked List node.
*/
typedef struct SListNode {
    void* data;
    struct SListNode* next;
} SListNode;

/**
 * \\brief Function pointer types for user-defined operations
 */
typedef void    (*SListFreeFn)(void*);
typedef void    (*SListPrintFn)(void*);
typedef int     (*SListCompareFn)(void*, void*);

/**
 * \\brief Append node to the end of the list
 */
SListNode* slist_append(SListNode* head, void* data);

/**
 * \\brief Insert node to the front of the list
 */
SListNode* slist_prepend(SListNode* head, void* data);

/**
 * \\brief Insert node in-order using comparison function
 */
SListNode* slist_add_inorder(SListNode* head, void* data, SListCompareFn cmp);

/**
 * \\brief Delete node with matching data using comparison function
 */
SListNode* slist_delete(SListNode* head, void* target, SListCompareFn cmp, SListFreeFn free_fn);

/**
 * \\brief Find first node with matching data
 */
void* slist_find(SListNode* head, void* target, SListCompareFn cmp);

/**
 * \\brief Traverse and apply print function to each node
 */
void slist_traverse(SListNode* head, SListPrintFn print_fn);

/**
 * \\brief Return number of nodes in the list
 */
int slist_length(SListNode* head);

/**
 * \\brief Free entire list
 */
void slist_free(SListNode* head, SListFreeFn free_fn);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SLIST_H_ */
