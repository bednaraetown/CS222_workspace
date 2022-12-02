/*************************************************
 *  CS 222: Systems Programming
 *  Elizabethtown College
 *  P. Li
 *  Main program for the Doubly Linked Lists
 *  Working with dynamic memory allocation
 
    **********************************************
    STUDENTS MUST WRITE CODE TO CORRECTLY COMPLETE
    THE MAIN FUNCTION BELOW. DO NOT MODIFY THE
    GIVEN FUNCTION readline()
    **********************************************
 
 *************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>                 // Header file for string functions
#include "DLList.h"                 // User-defined header file

int main(void) {
    DLList myList = {NULL, NULL};   // Doubly-linked list used throughout program
                                    // Since list is empty, firstNode and lastNode are
                                    //    both initialized to NULL
    char *cmd = NULL;               // Input command
    char *word = NULL;              // Input word 

    DLNode *targetNode;             // used when finding string

    do {
        printf("\nEnter command: ");
        cmd = readLine();           // Read string from standard input

        // Add word to list
        if (strcmp(cmd, "add") == 0) {
            printf("Enter word to be added: ");
            word = readLine();
            addNode(&myList, word);
        }

        // Delete word from list
        else if (strcmp(cmd, "delete") == 0) {
            printf("Enter word to be deleted: ");
            word = readLine();
            delNode(&myList, word);
        }

        // Find word in list
        else if (strcmp(cmd, "find") == 0) {
            printf("Enter word to be found: ");
            word = readLine();
            targetNode =  findNode(&myList, word);
            if(targetNode==NULL)
                printf("%s not found in list\n", word);
            else
                printf("%s found in list\n", word);
        }

        // Print contents of entire list
        else if (strcmp(cmd, "print") == 0){
            printList(&myList);
        }

        // Invalid command
        else if (strcmp(cmd, "exit") != 0)
            printf("Invalid command %s\n", cmd);
    } while (strcmp(cmd, "exit") != 0);

    return 0;
}
