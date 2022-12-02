/*________________ D O   N O T   M O D I F Y ! _______________*/
/*
 * CS 222: Systems Programming
 * Author: P. Li
 * Purpose: Starter file to raster graphics program
 *     Header file containing function prototypes
 */

#ifndef hw4_functions_h
#define hw4_functions_h

#define NRows 21    // Dimensions for grid
#define NCols 51

// Reset grid to original settings
void resetGrid(char grid[][NCols]);

// Add box to existing grid starting at (x, y) with specified width & height
void addBox(char grid[][NCols], int x, int y, int width, int height);

// Print current grid contents
void printGrid(char grid[][NCols]);

#endif /* hw4_functions_h */
