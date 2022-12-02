/*
 *  CS 222: Systems Programming
 *  proj3_main.c
 *  Author: August Bednar and Simon Burleson
 *  Purpose: The main file for Project 3
 */
#include <stdio.h>
#include "Rectangle.h"      // Includes "Point.h" as well
#include <math.h>
#include <ctype.h>

int main() {
    Rectangle rlist[10];    // Array containing up to 10 rectangles
    int nRect = 0;          // Number of rectangles
    char cmd;               // Single character command
    int ind, ind2;          // Loop index
    int flag;               // Flag to simplify conditionals
    int nread;              // Number of inputs read
    char junk;              // Used to clear input
    double p, a;
    char temp;
    do { // Big loop to repeat on request

        do { // First scan for end points
            printf("\n");
            printf("Enter command <A | P | D | O | Q>: ");
            nread = scanf(" %c", &cmd);
            temp = toupper(cmd);
            if (nread != 1){  // check for more than one character
                printf("Error: Improperly formatted input\n");
               printf("\n");
            }

            if (isalpha(cmd) == 0){ // Checks for a no commands
                printf("Error: Improperly formatted input\n");
                printf("\n");
            }

            do {
                scanf("%c", &junk);
            } while (junk != '\n');

        } while (nread != 1 || isalpha(cmd) == 0); // so long as no errors
        switch (temp)
        {
        case 'A':
            printf("Enter coordinates as x y, starting with lower left hand corner:\n");
            if(nRect != 10){
                for(int i = 0; i < 4; i++){
                    readPoint(&rlist[nRect].vert[i]);
                }
                nRect++;
            }
            else{
                printf("Max number of rectangles reached!\n");
            }
            break;
        case 'P':
            if(nRect == 0)
                printf("list is empty\n");
            else
                printList(rlist, nRect);
            break;
        case 'D':
            printf("Enter index into array: ");
            scanf("%d", &ind);
            p = perimeter(&rlist[ind]);
            a = area(&rlist[ind]);
            printf("Area of rectangle %d: %.2lf\n", ind, a);
            printf("Perimeter of rectangle %d: %.2lf\n", ind, p);
            break;
        case 'O':
            printf("Enter indices to test: ");
            scanf("%d %d", &ind, &ind2);
            flag = overlap(&rlist[ind], &rlist[ind2]);
            if(flag == 1)
                printf("Rectangles %d and %d overlap\n", ind, ind2);
            else
                printf("Rectangles %d and %d do not overlap\n", ind, ind2);
            break;
        case 'Q':
            return 0;
            break;

        default:
            printf("Invalid command %c\n", cmd);
            break;
        }
    

    } while (cmd != 'Q'); // checking if they want to.

}
