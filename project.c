#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

void readFile(LList *list);
char *nameReader();
void addName(LList *list);
void removeName(LList *list);
void writeToFile(LList *list);
void printMenu();

/* Reads file and creates a linked list based on the contents of the file */
void readFile(LList *list) {
  FILE *file;
  file = fopen("employee_database.txt", "rt");
  char line[50];

  while(fgets(line, 50, file) != NULL) {
    insertLinkedListNode(list, line);
  }

  fclose(file);
}

/* Reads user input for first name and last name */
char *nameReader() {
  char *firstName = (char *)malloc(26);
  char *lastName = (char *)malloc(26);
  char *fullName = (char *)malloc(50);
  int counter = 0;
  int i = 0;

  printf("Enter first name: ");
  scanf("%s", firstName);
  printf("Enter last name: ");
  scanf("%s", lastName);


  /* Copy first name into fullName string */
  while(firstName[counter] != '\0' && firstName[counter] != '\n') {
    fullName[counter] = firstName[counter];
    counter++;
  }
  
  /* Add whitespace between first name and last name */
  fullName[counter] = ' ';
  counter++;
 
  /* Copy last name into fullName string */
  while(lastName[i] != '\0') {
    fullName[counter] = lastName[i];
    counter++;
    i++;
  }
  fullName[counter] = '\0';
  return fullName;
}

/* Gets name to add and adds it to the linked list */
void addName(LList *list) {
  char *name = nameReader();
  insertLinkedListNode(list, name);
}

/* Gets name to delete and deletes it form the linked list */
void removeName(LList *list) {
  char *name = nameReader();
  removeLinkedListNode(list, name);
}

/* Writes the linked list to the file */
void writeToFile(LList *list) {
  FILE *file;
  LLNode *iterator;
  file = fopen("employee_database.txt", "w");
  
  for(iterator = list->first; iterator; iterator = iterator->next)
    fprintf(file, "%s\n", iterator->string);

  fclose(file);
}

void printMenu() {
  printf("-----------------------------------------------------------------------\n");
  printf("------------------Employee Database Management System------------------\n\n");
  printf("(1): List employee names\n");
  printf("(2): Add a new employee name\n");
  printf("(3): Remove an employee name\n");
  printf("(0): Quit program\n");
  printf("-----------------------------------------------------------------------\n");
}

int main() {
  LList *list = newLinkedList();
  readFile(list);
  int userChoice = -1;

  while(userChoice != 0) {
    printMenu();
    scanf("%d", &userChoice);
    printf("\n");

    /* Logic behind the choices */
    if(userChoice == 0)
      break;
    else if(userChoice == 1) {
      printf("Listing employee names:\n");
      printLinkedList(list);
      userChoice = -1;
    }
    else if(userChoice == 2) {
      addName(list);
      writeToFile(list);
      userChoice = -1;
    } else if(userChoice == 3) {
      removeName(list);
      writeToFile(list);
      userChoice = -1;
    }
    printf("\n\n");
  }
}
