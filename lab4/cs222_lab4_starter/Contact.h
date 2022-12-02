/*_________________ DO NOT MODIFY ____________________
 *
 *  Contact.h
 *  Author: P. Li
 *  Purpose: header file for Contact structure of lab 4
 */

#ifndef Contact_h
#define Contact_h

typedef struct {
    char name[50];       // First name of contact
    char email[50];      // Email address of contact
    char gender;         // Gender of contact - 'M' or 'F'
    unsigned int phone;  // Phone number of contact with 9 digits
} Contact;

// Print all contents of contact
void printContact(Contact* contact);

// Read information into existing contact
void readContact(Contact* contact);

#endif /* Contact_h */
