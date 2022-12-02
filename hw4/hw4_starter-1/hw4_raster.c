/*
 * CS 222: Systems Programming
 * Author: August Bednar
 * Purpose: File to raster graphics program
 *     C main file
 */

#include <stdio.h>
#include <string.h>
#include "hw4_functions.h"


int main(void) {
    char myGrid[NRows][NCols];  // The raster's 2D array
    int boxX, boxY;             // X and Y coordinates of box's
                                //     lower left corner
    int boxWidth, boxHeight;    // Rectangle's width and height
    char cmd[50];               // Input command
    
    resetGrid(myGrid);          // Initialize grid to clear state
    
    // LOOP TO REPEATEDLY PROMPT FOR AND EXECUTE INPUT COMMANDS
    do {
        // User prompt
        printf("\nEnter command: ");
       
        // Read in user's command as a string
        scanf("%s", cmd);
    
        if(strcmp(cmd, "print")==0){
            // If "print" COMMAND ENTERED--PRINT CURRENT STATE OF GRID
            printGrid(myGrid);
        } else if(strcmp(cmd, "reset")==0){
            // If "reset" COMMAND ENTERED--RESET GRID TO HAVE NO BOXES
            resetGrid(myGrid);
        } else if(strcmp(cmd, "add")==0){
            // If "add" COMMAND ENTERED--PROMPT FOR ORIGIN
            // COORDINATES (X,Y), WIDTH, AND HEIGHT, THEN
            // ADD BOX TO GRID
            printf("Enter X and Y coordinates for origin: ");
            scanf("%d %d", &boxX, &boxY);
            printf("Enter width and height: ");
            scanf("%d %d", &boxHeight, &boxWidth);
            addBox(myGrid, boxX, boxY, boxHeight, boxWidth);
        }else if(strcmp(cmd, "exit")==0){
            // If "exit" COMMAND ENTERED--END PROGRAM IMMEDIATELY
            return 0;
        }else{
            // If NO MATCHING COMMAND--PRINT ERROR MESSAGE & RE-PROMPT
            printf("Invalid command %s\n", cmd);
        }

        
    } while (1); // End of Do-While loop
    
    return 0;
}
