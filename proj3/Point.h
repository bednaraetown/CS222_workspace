/*
 *  CS 222: Systems Programming
 *  Point.h
 *  Author: P. Li
 *  Purpose: The function prototypes and
 *           Point structure definition
 */

#ifndef Point_h
#define Point_h

typedef struct {
    double x;        // X coordinate
    double y;        // Y coordinate
} Point;

// Print coordinates as (x.xx, y.yy)
void printPoint(Point *p);

// Read input coordinates
void readPoint(Point *p);

// Return distance between two points
double dist(Point *p1, Point *p2);

#endif /* Point_h */
