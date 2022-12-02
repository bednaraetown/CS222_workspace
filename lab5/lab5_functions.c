/*************************************************
   CS 222 Systems Programming
   P. Li
   Functions source file for lab5

   Contains function definitions for functions
   prototyped in lab5_functions.h

	********************************************** 
	STUDENTS MUST WRITE CODE TO CORRECTLY COMPLETE
	EACH FUNCTION DEFINITION BELOW, BUT SHOULD NOT
	MODIFY THE RETURN TYPE, NAME, OR ARGUMENTS OF
	ANY FUNCTION
	**********************************************

**************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "lab5_functions.h"


/********* F U N C T I O N   D E F I N I T I O N S *********/

/* THIS FUNCTION IS GIVEN, DO NOT MODIFY */
// Reads string from standard input and dynamically allocates space
// Assumes user input string terminates with '\n' (ENTER)
char *readCmd() {
    int i = 0;          // Loop index
    char *inStr;        // Input string
    char *tempStr;      // Temp string
    char inCh;          // Input character
    i = 0;

    inStr = (char *)malloc(1);	// Start with 1-character string
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
        else 
            inStr = tempStr;

        scanf("%c", &inCh); // Read the next character
    } 

    inStr[i] = '\0'; // Manually Null-terminate string
    return inStr;
}

/* THIS FUNCTION IS GIVEN, DO NOT MODIFY */
// Print contents of entire list
//   Each number takes the whole line
//   Print "List is empty" when list is empty
// Print contents of entire list
//   Each number takes the whole line
//   Print "List is empty" when list is empty
void printList(LLnode *list) {
    // Create pointer to start of list
    LLnode *n = list;

    if (n == NULL)
        printf("List is empty\n");

    else {
        // Loop to visit all nodes in list
        while (n != NULL) {
            printf("%d\n", n->value);
            n = n->next;
        }
    }
}


/* THIS FUNCTION IS GIVEN, DO NOT MODIFY */
// Add integer to list and return list's starting address
LLnode *addNode(LLnode *list, int v) {
    LLnode *newNode;

    // Allocate space for new node; exit if error
    newNode = (LLnode *)malloc(sizeof(LLnode));
    if (newNode == NULL) {
        printf("Error: could not allocate new node\n");
        freeList(list);
        exit(0);
    }

    newNode->value = v;     // Copy value to new node
    newNode->next = list;   // next points to old beginning of list
    return newNode;
}

/* THIS FUNCTION IS GIVEN, DO NOT MODIFY */
// Find node in list and return pointer
//   (or NULL if not found)
LLnode *findNode(LLnode *list, int v) {
    // Create pointer to start of list
    LLnode *n = list;

    // Loop to visit all nodes in list
    while (n != NULL) {
        // For current node:
        //   a. Check if data you want is in that node --> return address if so
        if (v == n->value) {
            return n;
        }

        //   b. Otherwise, move to the next node
        n = n->next;
    }

    // If data isn't found, return NULL
    return NULL;
}


/* THIS FUNCTION IS GIVEN, DO NOT MODIFY */
// Delete node from list (if present)
//   Return starting address of list when done
LLnode *delNode(LLnode *list, int v) {
    LLnode *prev = NULL;
    LLnode *cur = list;

    while (cur != NULL && v != cur->value) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {      // No match--went through entire list
        printf("%d not found in list\n", v);
        return list;
    }
    else {                  // Match found (v == cur->value), so delete cur node

        if (cur == list)    // Match found in first node
                            // Alternate condition: prev == NULL
            list = cur->next;

        else                // Match found outside of first node
            prev->next = cur->next;

        free(cur);
        printf("%d was deleted from list\n", v);
        return list;
    }
}

// Keep list sorted in ascending order
//   and add integer; return pointer to
//   start of list
LLnode *addSortedNode(LLnode *list, int v) {
    LLnode *prev = NULL;
    LLnode *cur = list;
    LLnode *newNode;
    newNode = (LLnode *)malloc(sizeof(LLnode));
    if (newNode == NULL) {
        printf("Error: could not allocate new node\n");
        freeList(list);
        exit(0);
    }

    while (cur != NULL && v > cur->value) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == list) {      // Special case to add to head
        newNode->value = v;
        newNode->next = list;
        list = newNode;
        return list;
    }
    else {                  // Add to any other point in list
        newNode->next = cur;
        prev->next = newNode;
        newNode->value = v;
        return list;
       
    }
    
}

// Find node in sorted list and return pointer
//   (or NULL if not found)
LLnode *findSortedNode(LLnode *list, int v) {
    LLnode *n = list;

    // Loop to visit all nodes in list
    while (n != NULL) {
        // For current node:
        //   a. Check if data you want is in that node --> return address if so
        if (v == n->value) {
            return n;
        }

        if(v < n->value){
            return NULL;
        }

        //   b. Otherwise, move to the next node
        n = n->next;
    }

    // If data isn't found, return NULL
    return NULL;
}

// Delete node from sorted list (if present)
//   Return starting address of list when done
LLnode *delSortedNode(LLnode *list, int v) {
    LLnode *prev = NULL;
    LLnode *cur = list;

    while (cur != NULL && v != cur->value && v>cur->value) {
        prev = cur;
        cur = cur->next;
    }

    
    if(cur->value == v){                  // Match found (v == cur->value), so delete cur node

        if (cur == list)    // Match found in first node
                            // Alternate condition: prev == NULL
            list = cur->next;

        else                // Match found outside of first node
            prev->next = cur->next;

        free(cur);
        printf("%d was deleted from list\n", v);
        return list;
    }else{      // No match--went through entire list
        printf("%d not found in list\n", v);
        return list;
    }
}

// Frees entire list before end of program to avoid memory leaks
void freeList(LLnode *list) {
    while (list !=NULL){
        LLnode *temp = list;
        list = list->next;
        free(temp);
    }
    
}