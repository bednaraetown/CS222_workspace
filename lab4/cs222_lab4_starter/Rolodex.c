/*
 *  Rolodex.c
 *  Author: August Bednar
 *  Purpose: c  file for Rolodex structure of lab 4
 */

#include "Rolodex.h"
#include <stdio.h>
#include <string.h>

// Print all existing contacts from the rolodex
void printRolodex(Rolodex* dex) {
    for (int i = 0; i < dex->size; i++)
	{
		printContact(&dex->contacts[i]);
		printf("\t--------------------\n");
	}
   
   }

// Add contact to the end of existing rolodex
void addContact(Rolodex* dex) {
    readContact(&dex->contacts[dex->size]);
    dex->size++;
    }

// Find a contact in list, based on first name
// Returns index if contact found, -1 otherwise
int findByName(Rolodex* dex, char fname[]) {
    for(int i = 0; i < dex->size; i++){
		if(strcmp(fname, dex->contacts[i].name) == 0) 
			return i;
	}
	return -1;
    }

// Find a contact in list, based on phone #
// Returns index if contact found, -1 otherwise
int findByPhone(Rolodex* dex, unsigned int num) {
    for(int i = 0; i < dex->size; i++){
		if(num == dex->contacts[i].phone)
			return i;
	}
	return -1;
    }