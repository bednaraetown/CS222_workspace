/*
 *  Contact.c
 *  Author: August Bednar
 *  Purpose: c file for Contact structure of lab 4
 */

#include "Contact.h"
#include <stdio.h>

// Print all contents of contact
void printContact(Contact* contact) {    
    
    printf("\t%s's email is <%s>.\n", contact->name, contact->email);
    if(contact->gender=='M' || contact->gender=='m'){
        //print him if Male
        printf("\tReach him at %.9u.\n", contact->phone);
    }else{
        //print her if Female
        printf("\tReach her at %.9u.\n", contact->phone);
    }
    
}

// Read information into existing contact
void readContact(Contact* contact) {
    char    junk;            // Character to clear the line
        printf("\tEnter name: ");
        scanf("%s", contact->name);

        printf("\tEnter email: ");
        scanf("%s", contact->email);

        do {
            scanf("%c", &junk);
        } while (junk != '\n');

        printf("\tEnter gender: ");
        scanf("%c", &contact->gender);

        printf("\tEnter phone: ");
        scanf("%u", &contact->phone);
    }