#include "../include/headerA3.h"

void printAll (struct employee * headLL) {

    // Initializing variables 
    a3Emp * temp;

    int value;
    int i;
    int counter = 1;

    // Checks if the linked list is empty 
    value = checkIfNull(headLL);

    if (value == 0) {
        printf("ERROR: The list is empty.\n");
        return;
    }

    temp = headLL;

    // While loop that prints every employee except the last one 
    while (temp->nextEmployee != NULL) {
        printf("Employee # %d: \n", counter);
        printf("\tEmployee id: %d \n", temp->empId);
        printf("\tFirst name: %s \n", temp->fname);
        printf("\tLast name: %s \n", temp->lname);
        printf("\tDependents [%d]: ", temp->numDependents);
        for (i = 0; i < (temp->numDependents - 1); i++) {
            printf ("%s, ", temp->dependents[i]);
        }
        printf ("%s ", temp->dependents[temp->numDependents - 1]);
        printf("\n\n");
        temp = temp->nextEmployee;
        counter++;
    }

    // Prints the last employee 
    printf("Employee # %d: \n", counter);
    printf("\tEmployee id: %d \n", temp->empId);
    printf("\tFirst name: %s \n", temp->fname);
    printf("\tLast name: %s \n", temp->lname);
    printf("\tDependents [%d]: ", temp->numDependents);
    for (i = 0; i < (temp->numDependents - 1); i++) {
        printf ("%s, ", temp->dependents[i]);
    }
    printf ("%s ", temp->dependents[temp->numDependents - 1]);
    printf("\n\n");

}