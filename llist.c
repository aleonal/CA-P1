#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

LList *newLinkedList() {
  LList *list = (LList *)malloc(sizeof(LList));
  list->first = list->last = 0;
  return list;
}

void insertLinkedListNode(LList *list, char *stringToAdd) {
  int length;
  char *stringCopy;
  LLNode *newNode;

  /* Computes the length of the string */
  for(length = 0; stringToAdd[length]; length++);

  /* Allocates exact space for stringCopy, considering the \0 character */
  stringCopy = (char *)malloc(length + 1);

  /* Copies contents of stringToAdd into the memory allocated for its copy */
  for(length = 0; stringToAdd[length]; length++)
    stringCopy[length] = stringToAdd[length];
  stringCopy[length] = 0;

  /* Instantiate the new node */
  newNode = (LLNode *)malloc(sizeof(LLNode));
  newNode->string = stringCopy;
  newNode->next = 0;

  /* Append new node and make it the last element */
  if(list->last)
    list->last->next = newNode;
  else 
    list->first = newNode;
  
  list->last = newNode;
}

void removeLinkedListNode(LList *list, char *stringToDelete) {
  LLNode *iterator;
  LLNode *previous = *list->first;
  int length;
  int isContained = 2;

  /* Loops while there are nodes in the list or until the string to delete is found */
  for(iterator = list->first; iterator; iterator = iterator->next) {
    /* Checks if the string in the current node is equal to the string we want to delete */
    for(length = 0; stringToDelete[length]; length++) {
      if(stringToDelete[length] != iterator->string[length]) {
	isContained = 0;
	break;
      }
    }

    /* If the list is empty, displays message and ends function. If it is not, and the matching word is found, loop exits.
       Otherwise, the pointers are moved down the list. */
    if(isContained == 0) {
      if(iterator != list->first)
	previous = previous->next;
      isContained = 2;
    } else {
      isContained = 1;
      break;
    }
  }

  if(isContained == 2) {
    printf("User does not exist!\n");
  }
  else
    printf("User was removed successfully!\n");

  /* Removes the node from the list */
  if(previous == list->first)             // If node to be removed is the head
    list->first = list->first->next;
  else                                   // If node to be removed is any other node
    previous->next = iterator->next;
}

void printLinkedList(LList *list) {
  LLNode *iterator;
  int count = 1;
  printf("List contents: \n");
  for(iterator = list->first; iterator; iterator = iterator->next) {
    printf("  %d: <%s>\n", count iterator->string);
    count++;
  }
}
