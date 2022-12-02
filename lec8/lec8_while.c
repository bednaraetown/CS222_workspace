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
    int numGrades; // Requested # of grades
    int gradeCount; // Counts # of grades processed so far
    double grade; // An individual grade to be processed
    double gradeSum; // Running total
    
    // Prompt for and read # of grades
    printf("How many grades? ");
    scanf("%d", &numGrades);
    
    // Prompt user to enter grades
    printf("Enter %d grades:\n", numGrades);

    // Initialize loop
    gradeSum = 0;  // Clear the accumulated grades
    gradeCount = 0; // Clear the accumulated counts of grades entered
    
    // Repeatedly read grades util limit is reached
    while (gradeCount < numGrades) {
        scanf("%lf", &grade); // Read grade and accumulated it
        gradeSum += grade;
        gradeCount += 1; // Increment grade count
    }
    
    // Compute and display the average
    printf("Average grade = %.1lf\n", gradeSum/numGrades);
    return 0;
}
