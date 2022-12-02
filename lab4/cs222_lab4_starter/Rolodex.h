/*_________________ DO NOT MODIFY ____________________
 *
 *  Rolodex.h
 *  Author: P. Li
 *  Purpose: header file for Rolodex structure of lab 4
 */

#ifndef Rolodex_h
#define Rolodex_h

#include "Contact.h"

// Rolodex data structure definition
typedef struct {
    Contact contacts[100]; // An array of contacts capped at 100
    int     size;          // Total contacts stored in the rolodex
} Rolodex;

// Print all existing contacts from the rolodex
void printRolodex(Rolodex* dex);

// Add contact to the end of existing rolodex
void addContact(Rolodex* dex);

// Find a contact in list, based on first name
// Returns index if contact found, -1 otherwise
int findByName(Rolodex* dex, char fname[]);

// Find a contact in list, based on phone #
// Returns index if contact found, -1 otherwise
int findByPhone(Rolodex* dex, unsigned int num);

#endif /* Rolodex_h */