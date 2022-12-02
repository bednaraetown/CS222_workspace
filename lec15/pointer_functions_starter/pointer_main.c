#include <stdio.h>
#include "pointer_functions.h"

int main() {
    /* SECTION 1: TEST FOR FUNCTION divQR() */
    printf("Test for function divQR():\n");
    // variable declaration
    int x = 15;
    int y = 6;
    int quotient;
    int remainder;

    // Make function call to divQR()
    
    

    // Print the results
    printf("Given x = %d, y = %d\n", x, y);
    printf("Division x/y, the quotient is %d, the remainder is %d.\n", 
           quotient, remainder);


    /* SECTION 2: TEST FOR FUNCTION swap() */
    printf("\nTest for function swap():\n");
    // variable declaration
    double num1 = 9;
    double num2 = 5;
    printf("num1 is %lf, num2 is %lf\n", num1, num2);

    // Make function call to swap()
    
    

    // Print the results
    printf("After swapping:\n");
    printf("num1 is %lf, num2 is %lf\n", num1, num2);

    /* SECTION 3: TEST FOR FUNCTION makeLower() */
    printf("\nTest for function makeLower():\n");
    // variable declaration
    char myChar = 'F';
    printf("Input character is: %c\n", myChar);

    // Make function call to swap()
    
    

    // Print the results
    printf("Final character is: %c\n", myChar);

    return 0;
}