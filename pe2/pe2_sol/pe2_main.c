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

    do {// Loop repeats until user enters 'X' or 'x'

        // Loop that gets the inputs and validates the inputs
        do {
            // Read input command and number to be used
            printf("Enter command and integer: ");
            nVals = scanf("%c %d", &cmd, &n);
            cmd = tolower(cmd);

            if (nVals != 2)
                printf("Error: incorrectly formatted input\n\n");
            else if (cmd != 'f' && cmd != 'P' && cmd != 'x')
                printf("Error: invalid command %c entered\n\n", cmd);
            else if (n < 0)
                printf("Error: invalid value for n\n\n");
                
            // Clear the line
            // Method 1: 
            // fflush(stdin); // Not recommended as it is not C standard

            // Method 2: 
            // while(getchar() != '\n'); 

            // Method 3: use scanf
            do {
                scanf("%c", &junk);
            } while (junk != '\n');
        } while (nVals != 2 || 
                 n < 0 || 
                 (cmd != 'f' && cmd != 'p' && cmd != 'x')
                );

        /* Evaluate cmd and perform appropriate operation */
        switch (cmd) {
        case 'f':
            result = factorial(n); // Calculate n!
            printf("%d! = %d\n\n", n, result);
            break;

        case 'p':
            result = power(n);  // Calculate 2^n
            printf("2^%d = %d\n\n", n, result);
            break;

        case 'x':
            break;  // Does nothing and moves to while condition check
        }
    } while (cmd != 'X' && cmd != 'x'); // Catch the exit sentinel

    return 0;
}
