/********************************************
 * File: lec17_main.c
 * Author: Dr. Li
 * Date: 03/20/2022
 * Purpose: Source file for the main()
 *          function. Demonstrates making 
 *          calls to functions with array
 *          arguments. 
 ********************************************/

#include <stdio.h>
#include "lec17_array_func.h"

int main(void) {
    int i;
    double myArr[] = {51, 62, 73, 84, 95, 100, 66, 57, 48, 79};
    int arrSize = sizeof(myArr) / sizeof(double);

    printf("Original array:\n");
    
    // TODO: Call printArray() to print the original array
    
    
    
    // TODO: Call findAvg() to get the average
    printf("Array average: %lf\n",          );

    // TODO: Call findMax() to get the max number
    printf("Array max: %lf\n",          );

    // TODO: Call sclAry() to add 10 to each array element
    

    printf("After scaling:\n");

    // TODO: Call printArray() to print array after scaling
    
    
        
    printf("\n");
    return 0;
}


