/* 
 * File: pe2_functions.c
 * Author: Dr. Li
 * Date: 02/18/2022
 * Description: Source file for function definitions
 */

// Preprocessor directives
#include "pe2_functions.h"

/* 
 * Name: factorial()
 * Arguments: num - integer 
 * Return: integer
 * Description: Function takes in an integer number num,
 *              and returns the factorial of num!
 */
int factorial(int num) {
    int result = 1;
    int i;
    for (i = num; i > 1; i--) {
        result *= i;
    }
    return result;
}

/* 
 * Name: power()
 * Arguments: num - int
 * Return: int
 * Description: Function takes in an integer number num,
 *              and returns 2 raise to the power of num
 */
int power(int num) {
    int result = 1;
    int i;
    for (i = 0; i < num; i++) {
        result *= 2;
    }
    return result;
}