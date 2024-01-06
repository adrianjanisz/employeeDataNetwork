#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne) {

    // Initializing variables 
    a3Emp * temp;
    
    int value;
    int i;
    
    // Checks if the linked list is empty 
    value = checkIfNull(headLL);

    if (value == 0) {
        printf("ERROR: The list is empty.\n");
        return;
    }

    temp = headLL;

    // Finds the employee chosen by the user 
    for (i = 0; i < whichOne - 1; i++) {
        temp = temp->nextEmployee;
    }

    // Prints the chosen employee's information 
    printf("\tEmployee id: %d \n", temp->empId);
    printf("\tFirst name: %s \n", temp->fname);
    printf("\tLast name: %s \n", temp->lname);
    printf("\tDependents [%d]: ", temp->numDependents);
    for (i = 0; i < (temp->numDependents - 1); i++) {
        printf ("%s, ", temp->dependents[i]);
    }
    printf ("%s ", temp->dependents[temp->numDependents - 1]);
    printf("\n");

}