/*************************************************
   CS 222 Systems Programming
   P. Li
   Header file for lab5: Dynamic memory allocation
   and data structures

   Contains LLnode structure definition, as well 
   as function prototypes

   ********DO NOT MODIFY THIS FILE *********
   
**************************************************/

#ifndef lab5_functions_h
#define lab5_functions_h

/********* N O D E   D E F I N I T I O N *********/

// Node definition for singly linked list of integers
typedef struct node {
	int value;
	struct node *next;
} LLnode;


/********* F U N C T I O N   P R O T O T Y P E S *********/

// Reads string from input and dynamically allocates space
char *readCmd();

// Print contents of entire list
void printList(LLnode *list);

// Add integer to list (unsorted)
//   and return pointer to new start of list
LLnode *addNode(LLnode *list, int v);		
							
// Find node in list and return pointer
//   (or NULL if not found)
LLnode *findNode(LLnode *list, int v);

// Delete node from list (if present)
LLnode *delNode(LLnode *list, int v);

// Keep list sorted in ascending order 
//   and add integer; return pointer to
//   start of list
LLnode *addSortedNode(LLnode *list, int v);

// Find node in sorted list and return pointer
//   (or NULL if not found)
LLnode *findSortedNode(LLnode *list, int v);

// Delete node from sorted list (if present)
//   Return starting address of list when done
LLnode *delSortedNode(LLnode *list, int v) ;

// Frees entire list before end of program
//   to avoid memory leaks
void freeList(LLnode *list);

#endif
