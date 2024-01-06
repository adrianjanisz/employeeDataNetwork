#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne) {

    // Initializing variables 
    a3Emp * temp;
    a3Emp * toRemove;

    int i;
    int counter = 2;

    temp = *headLL;

    if (whichOne == 1) { // Frees the first node if user input is 1 
        toRemove = temp;
        temp = temp->nextEmployee;
        for (i = 0; i < toRemove->numDependents; i++) { // Free 
            free(toRemove->dependents[i]);
        }
        free(toRemove->dependents);
        free(toRemove);
        *headLL = temp;
    }
    else { // Finds the node and frees it if user input is greater than 1 
        while (temp->nextEmployee != NULL || counter <= whichOne) {
            if (counter == whichOne) {
                toRemove = temp->nextEmployee;
                if (temp->nextEmployee->nextEmployee != NULL) { // Links the current node with the current->next->next node 
                    temp->nextEmployee = temp->nextEmployee->nextEmployee;
                }
                for (i = 0; i < toRemove->numDependents; i++) { // Free 
                    free(toRemove->dependents[i]);
                }
                free(toRemove->dependents);
                free(toRemove);
                if (temp->nextEmployee->nextEmployee == NULL) { // If there is no current->next->next node then the next node is set to NULL 
                    temp->nextEmployee = NULL;
                }
            }
            else {
                temp = temp->nextEmployee;
            }
            counter++;
        }
    }
}