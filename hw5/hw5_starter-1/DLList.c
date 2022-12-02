/*************************************************
 *  CS 222: Systems Programming
 *  Elizabethtown College
 *  P. Li
 *  DLList source file for Doubly Linked Lists
 *  Contains function definitions
 *************************************************

    ********************************************** 
    STUDENTS MUST WRITE CODE TO CORRECTLY COMPLETE
    EACH FUNCTION DEFINITION BELOW, BUT SHOULD NOT
    MODIFY THE RETURN TYPE, NAME, OR ARGUMENTS OF
    ANY FUNCTION
    **********************************************

**************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "DLList.h"

// Reads string from standard input and dynamically allocates space
// Assumes user input string terminates with '\n' (ENTER)
char *readLine() {
    int i = 0;          // Loop index
    char *inStr;        // Input string
    char *tempStr;      // Temp string
    char inCh;          // Input character
    i = 0;

    inStr = (char *)malloc(1);   // Start with 1-character string
    if (inStr == NULL) {
        printf("Could not allocate\n");
        return NULL;
    }

    scanf(" %c", &inCh); // Read the first character
    // Repeatedly read input characters and reallocate space to store string
    while (inCh != '\n') {
        inStr[i++] = inCh;
        tempStr = (char *) realloc(inStr, (i + 1) * sizeof(char));

        // Reallocation failed
        if (tempStr == NULL) {
            printf("Could not reallocate\n");
            return inStr;
        }

        // Reallocation successful; assign tempStr to inStr
        else inStr = tempStr;

        scanf("%c", &inCh); // Read the next character
    } 

    inStr[i] = '\0'; // Manually Null-terminate the string
    return inStr;
}

// Find node containing word
// Return pointer to node, or NULL if nothing found
DLNode *findNode(DLList *list, char *str) {
    DLNode *n = list->firstNode;

    // Loop to visit all nodes in list
    while (n != NULL) {
        // For current node:
        //   a. Check if data you want is in that node --> return address if so
        if (strcmp(n->word,str)==0) {
            return n;
        }

        if(strcmp(n->word,str)>0){
            return NULL;
        }

        //   b. Otherwise, move to the next node
        n = n->next;
    }

    // If data isn't found, return NULL
    return NULL;
}

// Add new node to list containing str
void addNode(DLList *list, char *str) {
    DLNode *curr = list->firstNode;
    DLNode *newNode;
    newNode = (DLNode *)malloc(sizeof(DLNode));
    if (newNode == NULL) {
        printf("Error: could not allocate new node\n");
        free(newNode);
        exit(0);
    }
    newNode->word = (char*)malloc(sizeof(str)+1); 
    if (newNode->word == NULL) {
        printf("Error: could not allocate new node\n");
        free(newNode->word);
        exit(0);
    }
    strcpy(newNode->word, str);
    

    //add node if no other nodes
    if(list->firstNode == NULL && list->lastNode == NULL){
        newNode->next = NULL;
        list->firstNode = newNode;
        list->lastNode = newNode;
        newNode->prev = NULL;        
    }else{
        //find right location
        while(curr !=NULL && strcmp(curr->word, newNode->word)<0){
        curr = curr->next;
        }
        if(curr == list->firstNode){     //add node to first position
            list->firstNode = newNode;
            curr->prev = newNode;
            newNode->prev = NULL;
            newNode->next = curr;                     
        }else if(curr == NULL){    //add node to last position
            list->lastNode->next = newNode;
            newNode->prev = list->lastNode;
            newNode->next = NULL;
            list->lastNode = newNode;

        }else{              //add node to other position
            curr->prev->next = newNode;
            newNode->next = curr;
            newNode->prev = curr->prev;
            curr->prev = newNode;
        }

    }
}

// Delete node containing word from list if it is present
void delNode(DLList *list, char *str) {
    DLNode *cur = findNode(list, str);

    if(cur!=NULL){                  // Match found, so delete cur node

        if (cur == list->firstNode && cur == list->lastNode){        // Only node
            list->firstNode = NULL;
            list->lastNode = NULL;
        }else if(cur == list->lastNode){     // is first node
            list->firstNode = list->firstNode->next;
            list->firstNode->prev = NULL;
            cur->next = NULL;
            cur->prev = NULL;
        }else if(cur == list->lastNode){      // is last node
            list->lastNode = list->lastNode->prev;
            list->lastNode->next = NULL;
            cur->next = NULL;
            cur->prev = NULL;
        }else{
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur->next = NULL;
            cur->prev = NULL;
        }             

        free(cur->word);
        free(cur);
        
    }

}

// Print contents of list, or message
void printList(DLList *list) {
    // Create pointer to head of list
    DLNode *n = list->firstNode;

    if (n == NULL)
        printf("\nList is empty\n");
    else {
        // Loop to visit all nodes in list
        printf("\nContents of list: \n");
        while (n != NULL) {
            printf("%s\n", n->word);
            n = n->next;
        }
    }    
}
