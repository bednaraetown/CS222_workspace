/*
 * while1.c
 * AUTHOR: P. Li
 * DATE: Feb 02, 2020
 *
 * PURPOSE: Read list of grades from keyboard and compute average
 *
 * DEMONSTRATES: A counting loop with a flexible limit
 */

#include <stdio.h>
int main()
{
    int gradeCount; // Counts # of grades processed so far
    double grade; // An individual grade to be processed
    double gradeSum; // Running total

    // Initialize loop
    gradeSum = 0;  // Clear the accumulated grades
    gradeCount = 0; // Clear the accumulated counts of grades entered

    
    // Repeatedly read grades util limit is reached
    do {
        printf("Enter grade: ");
        scanf("%lf", &grade); // Read grade and accumulated it
        if((grade>=0)&&(grade<=100)){
            gradeSum += grade;
            gradeCount += 1; // Increment grade count
        }   
        
    } while ((grade>=0)&&(grade<=100));
    
    // Compute and display the average
    printf("Average grade = %.1lf\n", gradeSum/gradeCount);
    return 0;
}
