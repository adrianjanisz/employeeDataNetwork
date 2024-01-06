#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL) {
    
    // Initializing variables 
    a3Emp * temp;

    int counter = 0;
    int value;
    
    // Checks if the linked list is empty 
    value = checkIfNull(headLL);

    if (value == 0) {
        return 0;
    }

    temp = headLL;

    // While loop that increments a counter until the end of the linked list is reached 
    while (temp != NULL) {
        temp = temp->nextEmployee;
        counter++;
    }

    return counter; // Returns the number of employees 

}