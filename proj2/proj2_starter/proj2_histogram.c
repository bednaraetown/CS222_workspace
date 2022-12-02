/*************************************************
    CS 222: System Programming
	Elizabethtown College
	August Bednar 
    Simon Burleson
	Main source file for histogram project
 ***************************************************/

#include <stdio.h>
#include "proj2_functions.h"

/* main function */
int main() {
    int hgram[26] = {0};  // Integer array holding frequency of each letter
    int maxFreq = 0;      // Maximum frequency for any letter
    char cmd;             // Single character command
    int i;                // Loop index

    char junk;
    // Parse command and execute command
    
    do{
    printf("Enter command (C, R, P, or Q): ");
    scanf(" %c", &cmd);
    printf("\n");
        switch (cmd)
        {
        case 'C': case 'c':
            for(i = 0; i < 26; i++){
               hgram[i] = 0;
            }
            maxFreq = 0;
            break;
        case 'R': case 'r':
            printf("ENTER A LINE OF TEXT:\n\n");
            readText(hgram, &maxFreq);
            break;
        case 'P': case 'p':
            drawHist(hgram, maxFreq);
            break;
        case 'Q': case 'q':
            return 0;
            break;
        default:
            printf("Invalid command %c\n\n", cmd);
            break;
        }
        do{
            scanf("%c", &junk);
        }while(junk!='\n');

    }while(cmd!='q' || cmd!='Q');
    

    

    return 0;
}
