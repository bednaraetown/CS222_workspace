/*
 *  CS 222: Systems Programming
 *  Rectangle.c
 *  Author: P. Li
 *  Purpose: The function definitions for
 *           Rectangle related functions
 */

#include "Rectangle.h"        // Implicitly includes Point.h
#include <stdio.h>
#include <math.h>

// Print contents of rectangle
// Prints vertices in appropriate relative positions:
//   vert[1]   vert[2]
//   vert[0]   vert[3]
void printRectangle(Rectangle *r) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    printf("(%.2lf , %.2lf) (%.2lf , %.2lf) \n", r->vert[1].x , r->vert[1].y , r->vert[2].x , r->vert[2].y);

    printf("(%.2lf , %.2lf) (%.2lf , %.2lf) \n", r->vert[0].x , r->vert[0].y , r->vert[3].x , r->vert[3].y);

}

// Print list of n Rectangles
void printList(Rectangle list[], int n) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    int i;
    for ( i = 0; i < n; i++){
        
        printRectangle(&list[i]);
        printf("\n");
    }
    
}

// Returns area of rectangle
double area(Rectangle *r) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    double area;

    area = dist(&r->vert[0], &r->vert[1]) * dist(&r->vert[1], &r->vert[2]);

    return area;
}

// Returns perimeter of rectangle
double perimeter(Rectangle *r) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    double perim;

    perim = dist(&r->vert[0], &r->vert[1]) + dist(&r->vert[1], &r->vert[2]) + dist(&r->vert[2], &r->vert[3]) + dist(&r->vert[3], &r->vert[0]);

    return perim;
}

// Returns 1 if two rectangles overlap; 0 otherwise
int overlap(Rectangle *r1, Rectangle *r2) {
    /*************************************************
     COMPLETE THIS FUNCTION WITH APPROPRIATE CODE
     *************************************************/
    int over = 0;

    if(r1->vert[1].y >= r2->vert[3].y  && r1->vert[1].x <= r2->vert[3].x)// overlap on top left of area of rectangle 1
    {
        over = 1;
        return over;
    }
    else if(r1->vert[0].x <= r2->vert[2].x && r2->vert[2].y >= r1->vert[0].y) // overlap of bottom left area of rectangle 1
    {
        over =1;
        return over;
    }
    else if(r2->vert[1].y >= r1->vert[3].y && r2->vert[1].x <= r1->vert[3].x ) // possible overlap on bottom right of rectangle 1
    {
        over =1;
        return over;
    }
    else if(r2->vert[0].x >= r1->vert[2].x && r1->vert[2].y >= r2->vert[0].y){    // possible overlap on top right side of rectangle 1
        over =1;
        return over;
    }
   
    return over;       // Modify the return statement as needed
}

