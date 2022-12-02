/**********************************************
    CS 222: System Programming
    Elizabethtown College
    P. Li
    Header file for integration project
    Tests ability to write and use functions
 ***********************************************/

// Lines used for conditional compilation
// ensures header isn't included multiple times
#ifndef proj1_functions_h
#define proj1_functions_h

// Calculate integral of f(x) over interval min to max, using n trapezoids
double integrate(double min, double max, int n);

// f(x) as defined in the specification
double f(double x);

// Used to clear line if input formatting error occurs
void badInput();

#endif /* More conditional compilation--end of proj1_functions_h */
