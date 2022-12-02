/*************************************************
   CS 222 System Programming
   P. Li
   Source file for demo: Dynamic memory allocation
   and data structures

   Contains main function for command line parsing
**************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LLnode.h"

// String Macro
#define HELP_MANUAL "Usage: program [-a NUM | -p | -f NUM | -d NUM]\n"

// readCmd() helper function prototype
char *readCmd();

int main (int argc, char ** argv) {
    LLnode *mylist = NULL;   // Node pointer to start of linked list
    LLnode *targetNode;      // Used when finding nodes
    char *cmd = NULL;	     // Input string command
    int inVal;               // Input value to be added/found/deleted
    char junk;               // Used to hold junk characters 

    // command line parsing
    if(argc == 2){
        if(strcmp(argv[1], "-p")==0){
            printList(mylist);
        }else{
            printf(HELP_MANUAL);
            exit(0);
        }
    }else if(argc == 3){
        if(strcmp(argv[1], "-a")==0){
            mylist = addNode(mylist, atoi(argv[2]));
        }else if(strcmp(argv[1], "-d")==0){
            mylist = delNode(mylist, atoi(argv[2]));
        }else if(strcmp(argv[1], "-f")==0){
           targetNode = findNode(mylist, atoi(argv[2]));
           if(targetNode==NULL)
                printf("%d not found in list\n", atoi(argv[2]));
            else
                printf("%d found in list\n", atoi(argv[2]));
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
        // Read string from standard input with readCmd() function
        cmd = readCmd();

        // Add integer to list
        if (strcmp(cmd, "add") == 0) {
            printf("Enter number to be added: ");
            // The space before %d tries to match junks 
            // from last input line, such as ENTER
            scanf(" %d", &inVal); 
            mylist = addNode(mylist, inVal);
        }
        // Delete node from list
        else if (strcmp(cmd, "delete") == 0) {
            printf("Enter number to be deleted: ");
            scanf(" %d", &inVal); 
            mylist = delNode(mylist, inVal);
        }
        // Find node in list
        else if (strcmp(cmd, "find") == 0) {
            printf("Enter number to be found: ");
            scanf(" %d", &inVal);
        
            targetNode = findNode(mylist, inVal);
            if(targetNode==NULL)
                printf("%d not found in list\n", inVal);
            else
                printf("%d found in list\n", inVal);
        }

        // Print contents of entire list
        else if (strcmp(cmd, "print") == 0) {
            printList(mylist);


        }
        // Invalid command
        else if (strcmp(cmd, "exit") != 0) {
            printf("Invalid command %s", cmd);
            return 0;
        }
    } while (strcmp(cmd, "exit") != 0);
    return 0;
}

// Reads string from standard input and dynamically allocates space
// Assumes user input string terminates with '\n' (ENTER)
char *readCmd() {

    char * inStr;
    char * tempStr;
    char inCh;
    int i = 0;

    //start off with single-char string
    inStr = (char *) malloc(sizeof(char));
    if(inStr==NULL){
        printf("Error: Could not allocate!\n");
        return NULL;
    }

    scanf(" %c", &inCh);
    while(inCh!='\n'){
        inStr[i] = inCh;
        i++;
        tempStr = (char *)realloc(inStr, sizeof(char)*i+1);
        if(tempStr==NULL){
            printf("Error: Could not allocate!\n");
            return NULL;
        }else
            inStr = tempStr;
        

        scanf("%c", &inCh);
    }
    inStr[i] = '\0';
    return inStr;
}
