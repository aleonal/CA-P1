#ifndef llist_H
#define llist_H

/* Linked list nodes: holds pointer to the next node and a pointer to character data */
typedef struct LLNode_s {
  struct LLNode *next;
  char *string;
} LLNode;

/* Linked list: holds pointers to the first and last nodes respectively */
typedef struct {
  LLNode *first, *last;
} LList;

/* Create a new linked list: allocates memory for a linked list structure */
LList *newLinkedList();

/* Insert element into list: copies provided string, creates a linked list node with the copy, and places it as last 
   in the given list */
void insertLinkedListNode(LList *list, char *stringToAdd);

/* Prints linked list */
void printLinkedList(LList *list);

#endif
