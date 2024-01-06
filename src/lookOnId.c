#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId) {

    // Initializing variables 
    a3Emp * temp;

    int counter = 1;
    int value;
    
    // Checks if the linked list is empty 
    value = checkIfNull(headLL);

    if (value == 0) {
        return -1;
    }

    temp = headLL;

    // While loop that checks if the inputted ID matches an employee ID 
    while (temp != NULL) {
        if (temp->empId == whichEmpId) {
            return counter; // Returns the employee number when the ID's match 
        }
        else {
            temp = temp->nextEmployee;
            counter++;
        }
    }

    return -2; // Returns -2 if no employee was found 

}