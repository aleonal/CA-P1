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
  LLNode *iterator = *list->first;
  LLNode *previous = *list->first;
  int length;
  int isContained = 1;

  /* Loops while there are nodes in the list or until the string to delete is found */
  while(*iterator != 0) {
    /* Checks if the string in the current node is equal to the string we want to delete */
    for(length = 0; stringToDelete[length]; length++) {
      if(stringToDelete[length] != iterator->string[length]) {
	isContained = 0;
	break;
      }
    }

    /* If the string is not equal, moves pointers down the list */
    if(isContained == 0) {
      if(iterator != list->first)
	previous = previous->next;
      iterator = iterator->next;
      isContained = 0;
    } else
      break;
  }

  /* Removes the node from the list */
  if(previous == list->first)             // If node to be removed is the head
    list->first = list->first->next;
  else                                   // If node to be removed is any other node
    previous->next = iterator->next;
}
