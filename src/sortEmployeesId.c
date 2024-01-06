#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL) {
    
    // Initializing variables 
    a3Emp * temp;

    int counter = 0;
    int counter2 = 0;
    int numOfEmp = 0;
    int i;
    int j;
    int tempNum;
    int value;
    
    // Checks if the linked list is empty 
    value = checkIfNull(headLL);

    if (value == 0) {
        printf("ERROR: The list is empty.\n");
        return;
    }

    temp = headLL;

    // Finds the number of employees 
    while (temp != NULL) {
        numOfEmp += 1;
        temp = temp->nextEmployee;
    }

    // Creates an integer array with the size of the number of employees 
    int array [numOfEmp];

    temp = headLL;

    // Stores all of the employee ID's into the array      
    while (temp != NULL) {
        array[counter] = temp->empId;
        temp = temp->nextEmployee;
        counter++;
    }

    // Sorts the array of ID's using bubble sort 
    for (i = 0; i < counter - 1; i++) {
        for (j = 0; j < counter - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                tempNum = array[j];
                array[j] = array[j+1];
                array[j+1] = tempNum;
            }
        }
    }

    temp = headLL;

    // Prints every employee 
    while (counter2 != counter) {
        if (temp->empId == array[counter2]) {
            printf("Employee # %d: \n", counter2 + 1);
            printf("\tEmployee id: %d \n", temp->empId);
            printf("\tFirst name: %s \n", temp->fname);
            printf("\tLast name: %s \n", temp->lname);
            printf("\tDependents [%d]: ", temp->numDependents);
            for (i = 0; i < (temp->numDependents - 1); i++) {
                printf ("%s, ", temp->dependents[i]);
            }
            printf ("%s ", temp->dependents[temp->numDependents - 1]);
            printf("\n\n");
            counter2++;
            temp = headLL;
        }
        else {
            temp = temp->nextEmployee;
        }
    }

}