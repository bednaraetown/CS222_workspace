/*************************************************
   CS 222 System Programming
   P. Li
   Source file for demo: Dynamic memory allocation
   and data structures

   Contains function definitions for functions
   prototyped in LLnode.h
**************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "LLnode.h"

// Add integer to list and return list's starting address
LLnode *addNode(LLnode *list, int v) {
    LLnode *newNode;

    // Allocate space for new node; exit if error
    newNode = (LLnode *)malloc(sizeof(LLnode));
    if (newNode == NULL) {
        printf("Error: could not allocate new node\n");
        free(list); //can be improved in lab 5
        exit(0);
    }

    newNode->value = v;     // Copy value to new node
    newNode->next = list;   // next points to old beginning of list
    return newNode;
}

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

// Delete node from list (if present)
// Return starting address of list when done
LLnode *delNode(LLnode *list, int v) {
    LLnode *prev = NULL;
    LLnode *cur = list;
    while(cur != NULL && v != cur->value){
        prev = cur;
        cur = cur->next;
    }
    if(cur==NULL){
        return list;
    }else{
        if(cur==list)
            list = cur->next;
        else
            prev->next = cur->next;
        free(cur);
        return list;
    }
}

// Print contents of entire list
void printList(LLnode *list) {
    LLnode *n = list;
    if(n==NULL)
        printf("WARNING: List is empty!\n");
        else{
            while (n != NULL){
                printf("%d\n", n->value);
                n = n->next;
            }
            
        }



}
