#include "../include/headerA3.h"

int main () {
    
    // Initializing linked list 
    a3Emp * a3LinkedList = NULL;
    a3Emp * temp;

    // Load data from file into a linked list 
    loadEmpData(&a3LinkedList, "proFile.txt");

    // Initializing variables 
    int i;
    int validationValue = 1;
    int userChoice = 0;
    int value;
    int userInput1;
    int numOfEmp;
    int validInputs;
    int userInput2;
    int empPosition;
    char userInput3 [100];
    int empPosition2;
    int userInput4;
    char userInput5;
    // While loop that runs until user chooses option 10 (Exits program) 
    while (validationValue == 1) {
        // Menu 
        printf("\nChoose one of the following options: \n");
        printf("1.  Add a new employee \n");
        printf("2.  Print data of all employees \n");
        printf("3.  Print data of the nth employee \n");
        printf("4.  Search for employee based on empld \n");
        printf("5.  Search for employee based on full name \n");
        printf("6.  Count the total number of employees \n");
        printf("7.  Sort the employees based on their empld \n");
        printf("8.  Remove the nth employee in the current LL \n");
        printf("9.  Remove all employees in the current LL \n");
        printf("10. Exit \n");

        // User menu input 
        printf("\nEnter a choice (1 - 10): ");
        scanf("%d", &userChoice);
        printf("\n");

        // User menu input validation 
        while (userChoice <= 0 || userChoice >= 11) {
            printf("Invalid choice. Please choose again: ");
            scanf("%d", &userChoice);
            printf("\n");
        }
        
        // Block of if statements that runs functions according to user input. 
        if (userChoice == 1) { // Runs the function recruitEmployee, allows user to add an employee. 
            recruitEmployee(&a3LinkedList);
        }
        else if (userChoice == 2) {
            printAll(a3LinkedList); // Runs the function printAll, prints all the employees in the linked list. 
        }
        else if (userChoice == 3) { // Runs the function printOne, prints X employee, X is the user input. countEmployees and checkIfNull are used in this function for input validation. 
            validInputs = countEmployees(a3LinkedList);
            printf("Enter which employee to print: ");
            scanf("%d", &userInput1);
            printf("\n");
            value = checkIfNull(a3LinkedList);
            if (value == 0) { // If linked list is empty. 
                printf("ERROR: The list is empty.\n");
            }
            else { // If linked list is not empty. 
                while (userInput1 < 1 || userInput1 > validInputs) { // Input validation, makes sure the user inputs a value that can be printed. 
                    printf("Invalid choice. Please choose again: ");
                    scanf("%d", &userInput1);
                    printf("\n");
                }
                printOne(a3LinkedList, userInput1);
            }
        }
        else if (userChoice == 4) { // Runs the function lookOnId, prints the employee with the inputted ID, otherwise prints that the employee doesnt exist. If the linked list is empty, it will print an error message. 
            printf("Enter an employee ID: ");
            scanf("%d", &userInput2);
            empPosition = lookOnId(a3LinkedList, userInput2);
            printf("\n");
            if (empPosition == -2) { // If employee is not found. 
                printf("No employee with ID: %d was found.\n", userInput2);
            }
            else if (empPosition == -1) { // If linked list is empty. 
                printf("ERROR: The list is empty.\n");
            }
            else { // If employee is found. 
                printOne(a3LinkedList, empPosition);
            }
            empPosition = 0;
        }
        else if (userChoice == 5) { // Runs the function lookOnFullName, prints the employee with the inputted name, otherwise prints that the employee doesnt exist. If the linked list is empty, it will print an error message. 
            printf("Enter the full name of the employee: ");
            getchar();
            fgets(userInput3, 100, stdin);
            empPosition2 = lookOnFullName(a3LinkedList, userInput3);
            printf("\n");
            if (empPosition2 == -2) { // If employee is not found. 
                printf("No employee with name that name was found.\n");
            }
            else if (empPosition2 == -1) { // If linked list is empty. 
                printf("ERROR: The list is empty.\n");
            }
            else { // If employee is found. 
                printOne(a3LinkedList, empPosition2);
            }
            empPosition2 = 0;
        }
        else if (userChoice == 6) { // Runs the function countEmployees, prints the total number of employees. If the linked list is empty, it will print an error message. 
            numOfEmp = countEmployees(a3LinkedList);
            if (numOfEmp == 0) { // If linked list is empty. 
                printf("ERROR: The list is empty.\n");
            }
            else { // If linked list is not empty. 
                printf("Total number of employees = %d\n", numOfEmp);
            }
        }
        else if (userChoice == 7) { // Runs the function sortEmployeesId, prints all employees in ascending ID order. If the linked list is empty, it will print an error message. 
            sortEmployeesId(a3LinkedList);
        }
        else if (userChoice == 8) { // Runs the function fireOne, removes X employee from the linked list, X is the user input. If the linked list is empty, it will print an error message. 
            numOfEmp = countEmployees(a3LinkedList);
            if (numOfEmp == 0) { // If linked list is empty. 
                printf("ERROR: The list is empty.\n");
            }
            else { // If linked list is not empty. 
                printf("Total number of employees = %d\n\n", numOfEmp);
                printf("Which employee do you wish to fire (1 - %d): ", numOfEmp);
                scanf("%d", &userInput4);
                while (userInput4 < 1 || userInput4 > numOfEmp) { // Input validation, makes sure the user inputs a value for an employee that can be fired. 
                    printf("Invalid choice. Please choose again: ");
                    scanf("%d", &userInput4);
                    printf("\n");
                }
                fireOne(&a3LinkedList, userInput4);
                printf("\nThere are now %d employees.\n", numOfEmp - 1);
            }

        }
        else if (userChoice == 9) { // Runs the function fireAll, removes all employees from the linked list. If the linked list is empty, it will print an error message. 
            printf("Are you sure you want to fire everyone (y to continue): ");
            getchar();
            scanf("%c", &userInput5);
            if (userInput5 == 'y') { // If user inputs y. 
                fireAll(&a3LinkedList);
            }
            else { // If user does not input y. 
                printf("\nNobody was fired.\n");
            }
        }
        else if (userChoice == 10) { // Frees the linked list and exits the program. 
            while (a3LinkedList != NULL) {
		        temp = a3LinkedList;
		        a3LinkedList = a3LinkedList->nextEmployee;
		        for (i = 0; i < temp->numDependents; i++) {
                    free(temp->dependents[i]);
                }
                free(temp->dependents);
                free(temp);
	        }
            validationValue = 0;
            return 0;
        }

    }

}