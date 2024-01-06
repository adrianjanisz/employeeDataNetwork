#include "../include/headerA3.h"

void fireAll (a3Emp ** headLL) {
    
    // Initializing variables 
    a3Emp * temp;
    a3Emp * temp2;

    int i;
    int value;
    
    // Checks if the linked list is empty 
    value = checkIfNull(*headLL);

    if (value == 0) {
        printf("ERROR: The list is empty.\n");
        return;
    }

    temp = *headLL;

    // While loop that runs until the end of the linked list 
    while (temp != NULL) {
        temp2 = temp;
        temp = temp->nextEmployee;
        for (i = 0; i < temp2->numDependents; i++) { // Free 
            free(temp2->dependents[i]);
        }
        free(temp2->dependents);
        free(temp2);
    }

    *headLL = temp; // Set the array to empty 

}