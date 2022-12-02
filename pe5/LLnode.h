/*************************************************
   CS 222 System Programming
   P. Li
   Header file for demo: Dynamic memory allocation
   and data structures

   Contains LLnode structure definition, as well 
   as function prototypes
**************************************************/

// Node definition for singly linked list of integers
typedef struct node {
    int value;
    struct node *next;
} LLnode;

// Function prototypes
LLnode *addNode(LLnode *list, int v);       // Add integer to list (unsorted)
                                            //   and return pointer to new start of list
LLnode *findNode(LLnode *list, int v);      // Find node in list and return pointer
                                            //   (or NULL if not found)
LLnode *delNode(LLnode *list, int v);       // Delete node from list (if present)
void printList(LLnode *list);               // Print contents of entire list

