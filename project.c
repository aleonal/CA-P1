#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

/* Reads file and creates a linked list based on the contents of the file */
void readFile(LList *list) {
  FILE *file;
  file = fopen("employee_database.txt", "rt");
  char line[40];

  while(fgets(line, 40, file) != NULL) {
    insertLinkedListNode(list, line);
  }

  fclose(file);
}

int main() {
  LList *list = newLinkedList();
  LLNode *temp;
  readFile(list);
  printLinkedList(list);
}
