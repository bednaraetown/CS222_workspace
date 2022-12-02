/*
 * CS 222: Systems Programming
 * Author: August Bednar
 * Purpose: File to raster graphics program
 *     C file containing functions
 */

#include <stdio.h>
#include "hw4_functions.h"

// Reset grid to original settings
void resetGrid(char grid[][NCols]) {
	int row,col;
   	for(row=0;row<NRows;row++){
		for(col=0;col<NCols;col++){
		   if(row%5==0){
			   if(col%5==0)
			   		grid[row][col]='+';
				else
					grid[row][col]='-';
			}else{
				if(col%5==0)
					grid[row][col]='|';
				else
					grid[row][col]=' ';
			}
		}
	}
}

// Add box to existing grid starting at (x, y) with specified width & height
void addBox(char grid[][NCols], int x, int y, int width, int height){
    int row,col;
	//while loops to compensate for input out of grid
	while(x<0){
    	x++;
        width--;
	}
    while(y<0){
        y++;
        height--;
    }


    for(row=y;row<y+height;row++)
    {
        for(col=x;col<x+width;col++)
        {
            if(row<NRows&&col<NCols)
            grid[row][col]='*';//adds star to cell 
        }
    }
}

// Print current grid contents
void printGrid(char grid[][NCols]) {
    int i, j;        // Row and column numbers
    
    /* Print grid and any boxes, starting with the top row (row = 20) and left-most
     column (col = 0). If coordinate is part of box, will print '*'.
     Otherwise, if coordinate is part of grid, print appropriate character.
     Grid lines are printed every 5 rows and columns.
     Print one row at a time, for a total of 51 rows and 21 columns */
    int row,col;
    printf("\n");
    for(row=NRows-1;row>=0;row--)
       {
            for(col=0;col<NCols;col++)
            {
                printf("%c",grid[row][col]);
    
            }
            if(row%5==0)
            printf("%d",row);
            printf("\n");
        
        
       }
    
    // Lastly, print x axis legend (column numbers) separately
    printf("0    5    10   15   20   25   30   35   40   45   50\n");
}
