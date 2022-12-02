/*************************************************
   CS 222 Systems Programming
   P. Li
   Main program for lab5: Dynamic memory allocation
   and data structures

   Works with singly linked list, which is defined
   in separate file


   **** COMPLETE THIS FILE AS NEEDED ****
   
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab5_functions.h"	 // Contains function prototypes
#define HELP_MANUAL "Usage: ./lab5 [-s | -u]\n"

int main(int argc, char ** argv) {
    LLnode *mylist = NULL;   // Node pointer to start of linked list
    LLnode *targetNode;      // Used when finding nodes
    char *cmd = NULL;        // Input string command
    int inVal;               // Input value to be added/found/deleted
    int numVal;              // 1 - sorted, 0- unsorted

    // Command line parsing: checks if valid flags are specified
    if(argc == 2){
        if(strcmp(argv[1], "-s")==0){
            printf("Using sorted linked list.\n");
            numVal = 1;

        }else if(strcmp(argv[1], "-u")==0){
            printf("Using unsorted linked list.\n");
            numVal = 0;
        }else{
            printf(HELP_MANUAL);
            exit(0);
        }
    }else{
        printf(HELP_MANUAL);
        exit(0);
    }


    // Loop to check and execute the user's command
    //   Only breaks out when receives "exit"
    
    do {
                // Prompt user to enter a string command
                printf("\nEnter command: ");
                // Free dynamic string cmd from the last iteration
                free(cmd);
                // Read string from standard input with readCmd() function
                cmd = readCmd();

                // Add integer to list
                if (strcmp(cmd, "add") == 0) {
                    printf("Enter number to be added: ");
                    // The space before %d tries to match junks 
                    // from last input line, such as ENTER
                    scanf(" %d", &inVal); 
                    if(numVal==1){
                        mylist = addSortedNode(mylist, inVal);
                    }else{
                        mylist = addNode(mylist, inVal);
                    }
                     
                    
                }   
                // Delete node from list
                else if (strcmp(cmd, "delete") == 0) {
                    printf("Enter number to be deleted: ");
                    scanf(" %d", &inVal); 
                    if(numVal==1){
                        mylist = delSortedNode(mylist, inVal);
                    }else{
                        mylist = delNode(mylist, inVal);
                    }
                    
                }
                // Find node in list
                else if (strcmp(cmd, "find") == 0) {
                    printf("Enter number to be found: ");
                    scanf(" %d", &inVal);
                    if(numVal==1){
                        targetNode = findSortedNode(mylist, inVal);
                    }else{
                        targetNode = findNode(mylist, inVal);
                    }
                    
                    if(targetNode==NULL)
                        printf("%d not found in list\n", inVal);
                    else
                        printf("%d found in list\n", inVal);
                }
                // Print contents of entire list
                else if (strcmp(cmd, "print") == 0) {
                    printList(mylist);
                }
                //exit command
                else if(strcmp(cmd, "exit") == 0){
                    freeList(mylist);
                    return 0;
                }
                // Invalid command
                else{
                    printf("Invalid command %s\n", cmd);
                }
            } while (strcmp(cmd, "exit") != 0);

    freeList(mylist);
    return 0;
}
