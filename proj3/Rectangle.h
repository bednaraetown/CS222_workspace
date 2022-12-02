/*
 *  CS 222: Systems Programming
 *  Rectangle.h
 *  Author: P. Li
 *  Purpose: The function prototypes and
 *           Rectangle structure definition
 */

#ifndef Rectangle_h
#define Rectangle_h

#include "Point.h"

typedef struct {
    Point vert[4];        // List of 4 vertices
    // Functions all assume that vert[0] = lower left corner,
    //   vert[1] = upper left corner
    //   vert[2] = upper right corner,
    //   vert[3] = lower right corner
} Rectangle;

// Print contents of rectangle
void printRectangle(Rectangle *r);

// Print list of n Rectangles
void printList(Rectangle list[], int n);

// Returns area of rectangle
double area(Rectangle *r);

// Returns perimeter of rectangle
double perimeter(Rectangle *r);

// Returns 1 if two rectangles overlap; 0 otherwise
int overlap(Rectangle *r1, Rectangle *r2);

#endif /* Rectangle_h */
