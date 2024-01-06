#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100]) {

    // Initializing variables 
    a3Emp * temp;

    char delimeter [2] = " ";
    char *tempString;
    char properFirstName [MAX_LENGTH];
    char properLastName [MAX_LENGTH];
    int counter = 1;
    int i;
    int value;
    
    // Checks if the linked list is empty 
    value = checkIfNull(headLL);

    if (value == 0) {
        return -1;
    }

    // Splits the inputted string into first name and last name 
    tempString = strtok(whichName, delimeter);
    strcpy(properFirstName, tempString);

    tempString = strtok(NULL, delimeter);
    strcpy(properLastName, tempString);
    properLastName[strlen(properLastName) - 1] = '\0';

    // Makes both first and last name all lowercase 
    for (i = 0; i < strlen(properFirstName); i++) {
            properFirstName[i] = tolower(properFirstName[i]);
        }
    for (i = 0; i < strlen(properLastName); i++) {
            properLastName[i] = tolower(properLastName[i]);
        }

    temp = headLL;

    // Compare inputted first and last name to first and last names of employees in linked list 
    while (temp != NULL) {
        for (i = 0; i < strlen(temp->fname); i++) {
            temp->fname[i] = tolower(temp->fname[i]);
        }
        for (i = 0; i < strlen(temp->lname); i++) {
            temp->lname[i] = tolower(temp->lname[i]);
        }
        if (strcmp(temp->fname, properFirstName) == 0) {
            if (strcmp(temp->lname, properLastName) == 0) {
                temp->fname[0] = toupper(temp->fname[0]);
                temp->lname[0] = toupper(temp->lname[0]);
                temp = headLL;
                for (i = 0; i < counter; i++) { // Makes all names start with a capital 
                    temp->fname[0] = toupper(temp->fname[0]);
                    temp->lname[0] = toupper(temp->lname[0]);
                    temp = temp->nextEmployee;
                }
                return counter; // Returns the employee number when the names match 
            }
            else {
                counter++;
            }
        }
        else {
            temp = temp->nextEmployee;
            counter++;
        }
    }
    
    return -2; // Returns -2 if no employee was found 

}