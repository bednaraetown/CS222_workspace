//////////////////////////////////////////
// YOU SHOULD NEVER MODIFY THIS FILE!!! //
//////////////////////////////////////////

/**********************************************
    CS 222: Systems Programming
    Elizabethtown College
    P. Li
    Header file for Histogram
 ***********************************************/


// Lines used for conditional compilation
// ensures header isn't included multiple times
#ifndef proj2_functions_h
#define proj2_functions_h

/* Function prototypes */

/* Reads single line of text and updates histogram
 as well as frequency of most frequent letter */
void readText(int histo[], int *max);

/* Prints histogram, using array holding values
 as well as frequency of most frequent letter,
 which determines height of histogram */
void drawHist(int histo[], int max);

#endif /* More conditional compilation--end of proj1_functions_h */
