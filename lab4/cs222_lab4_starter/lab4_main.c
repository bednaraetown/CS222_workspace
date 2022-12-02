/*
 *  leab4_main.c
 *  Author: August Bednar
 *  Purpose: c file for main structure of lab 4
 */

#include "Rolodex.h"         // Also includes Contact.h
#include <stdio.h>


int main() {
    char    cmd;             // Single character command
    char    junk;            // Character to clear the line
    int     ret;             // Return of scanf()
    
    Rolodex mydex;	         // A rolodex struct
    mydex.size = 0;          // Reset the size of the rolodex

    int  opt;                // Number option for searching command
    unsigned int phone2Find; // Phone number to be found
    char name2Find[50];      // The name to be found
    int  index;              // Index of found contact

    // Loop until user enters 'Q'
    while (1) {
        printf("\nEnter command for Rolodex <A | P | F | Q>: ");
        scanf(" %c", &cmd);
        
        switch (cmd) {
            
        // Add contact to rolodex
        case 'A': case 'a':
            if (mydex.size == 100)		// Rolodex is full
                printf("\tError: no room in Rolodex!\n");
            else {
                addContact(&mydex);
            }
            break;
            
        // Print the list of contacts from rolodex
        case 'P': case 'p':
            if(mydex.size == 0){
                printf("\tRolodex is empty!\n");
            }else{
                printRolodex(&mydex);
            }
            
            
            break;
            
        // Find a particular contact
        case 'F': case 'f':
            do {
                printf("\tEnter 1 to find by name, 2 to find by phone: ");
                ret = scanf(" %d", &opt);
                if (ret != 1) {
                    printf("\tError: incorrectly formatted input!\n");
                    do {
                        scanf("%c", &junk);
                    } while (junk != '\n');
                }
            } while(ret != 1);
    
            switch (opt) {
                case 1:
                    printf("\tEnter name to be found: ");
                    scanf("%s", name2Find);

                    index = findByName(&mydex, name2Find);

                    break;
                    
                case 2:
                    printf("\tEnter phone to be found: ");
                    scanf("%u", &phone2Find);

                    index = findByPhone(&mydex, phone2Find);

                    break;
                    
                default:
                    printf("\tError: invalid selection!\n");
                    do {
                        scanf("%c", &junk);
                    } while (junk != '\n');
                    index = -2;
            }
            
            // Check results of find function
            if (index == -1)
                printf("\tContact not found!\n");
            else if (index >= 0) {
                printf("\tContact found\n");

                printContact(&mydex.contacts[index]);

            }
            break;
            
        // Exit program
        case 'Q': case 'q':
            return 0;
            
        default:
            printf("\tError: invalid command %c\n", cmd);
        }
    }
}
