#include "../include/headerA3.h"

void recruitEmployee (struct employee ** headLL) {

    // Initializing structs 
    a3Emp * temp;
    a3Emp * newNode = malloc(sizeof(a3Emp));

    // Initializing variables 
    char first [MAX_LENGTH];
    char last [MAX_LENGTH];
    char userChoice;
    int counter = 0;
    int counter2 = 1;
    int i;
    int idNum = 0;
    int numDep = 5;
    int randomNum;

    // Check if list is empty 
    if (*headLL == NULL) {
        *headLL = newNode;
    }

    temp = *headLL;

    // Find end of linked list 
    while (temp->nextEmployee != NULL) {
        temp = temp->nextEmployee;
    }

    temp->nextEmployee = newNode;

    newNode->nextEmployee = NULL;
    
    // Input employee info 
    printf("Enter the first name of the employee: ");
    scanf("%s", first);
    strcpy(newNode->fname, first);
    
    printf("Enter the last name of the employee: ");
    scanf("%s", last);
    strcpy(newNode->lname, last);

    // Dynamically allocate 2D array 
    char ** array = malloc(sizeof(char *) * numDep);
    
    for (i = 0; i < 5; i++) {
        array[i] = malloc(sizeof(char) * MAX_LENGTH);
    }

    // Input dependents 
    printf("\nEnter the name of dependent #%d: ", counter + 1);
    scanf("%s", array[counter]);
    getchar();

    printf("Do you have more dependents? ");
    scanf("%c", &userChoice);

    // While loop for more than 1 dependent 
    while ((userChoice == 'Y') || (userChoice == 'y')) {

        counter++;
        counter2++;

        printf("\nEnter the name of dependent #%d: ", counter + 1);
        
        scanf("%s", array[counter]);
        
        getchar();
        
        printf("Do you have more dependents? ");
        
        scanf("%c", &userChoice);

        if (counter2 == numDep) {
            numDep = numDep + 5;
            array = realloc(array, sizeof(char *) * numDep);
            for (i = numDep - 5; i < numDep; i++) {
                array[i] = malloc(sizeof(char) * MAX_LENGTH);
            }
        }
        
    }

    printf("\nYou have %d dependents. \n\n", counter + 1);

    // Copy dependents from the array to the linked list 
    newNode->dependents = malloc(sizeof(char) * counter2);
    for (i = 0; i < counter2; i++) {
        newNode->dependents[i] = malloc(sizeof(char) * MAX_LENGTH);
        strcpy(newNode->dependents[i], array[i]);
    }

    // Employee ID 
    for (i = 0; i < strlen(newNode->fname); i++) {
        idNum = idNum + newNode->fname[i];
    }

    idNum = idNum + strlen(newNode->lname);

    temp = *headLL;
    
    // Check for duplicate ID's 
    while (temp->nextEmployee != NULL) {
        if (temp->empId == idNum) {
            srand(time(NULL));
            randomNum = rand() % 999;
            idNum = idNum + randomNum;
            temp = *headLL;
        }
        temp = temp->nextEmployee;
    }
    
    newNode->empId = idNum;

    // Final function print statement 
    printf("Your computer-generated empId is %d \n\n", newNode->empId);

    newNode->numDependents = counter + 1;

    // Free 
    for (i = 0; i < numDep; i++) {
        free(array[i]);
    }
    free(array);

}
