/* 
 * File: pe2_main.c
 * Author: Dr. Li
 * Date: 02/18/2022
 * Description: Source file for main function of PE2
 * Copyright © 2022 Etown. All rights reserved.
 */


// Preprocessor directives
#include <stdio.h>
#include <ctype.h>
#include "pe2_functions.h"

int main() {
    char cmd;		// Input command
    int n;			// Integer used in calculations
    char junk;		// Used to clear line
    int nVals;		// # values read
    int result;     // Result for the calculations

    // COMPLETE THE REST OF THE MAIN FUNCTION
    do{
        //loop that prompts for and reads inputs
        //validate input until correctly formated
        do{
            printf("Enter for a command and a number (cmd n): ");
            nVals = scanf("%c %d", &cmd, &n);
            cmd = tolower(cmd);

            if(nVals < 2) // Type 1 error
                printf("Error: incorrectly formatted input\n\n");
            else if((cmd!='f') && (cmd != 'p') && (cmd != 'x')) // Type 2 error
                printf("Error: invalid command %c entered\n\n", cmd);
            else if(n<0) // Type 3 error
                printf("Error: invalid value for n");
            
            //Mini loop that consumes leftovers from pipe
            do{
                scanf("%c", &junk);
            }while(junk != '\n');

        }while((nVals < 2) || ((cmd!='f') && (cmd != 'p') && (cmd != 'x')) || (n<0));
        
        switch(cmd){
            case 'f':
            //calls factorial function
            result = factorial(n);
            printf("%d! = %d", n, result);
            break;

            case 'p':
            //calls power function
            result = power(n);
            printf("2^%d = %d", n, result);
            break;

            case 'x':
            //does nothing
            break;
        }
    }while(cmd!='x');

    return 0;
}
