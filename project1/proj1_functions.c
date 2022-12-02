/**********************************************
	CS 222: System Programming
	Elizabethtown College
	August Bednar 
    Seamus Corr
	Function source file for integration project
	Tests ability to write and use functions
 ***********************************************/

#include <stdio.h>
#include <math.h>
#include "proj1_functions.h"

// Calculate integral of f(x) over interval min to max, using n trapezoids
double integrate(double min, double max, int n) {
	int i;
    double x[n+1],y[n+1];
    double h;
    double sum=0;
    h = (max - min) / n;                
    for (i = 0; i <= n; i++) {      
       x[i] = min + i * h;            
       y[i] = f(x[i]);
    }
    for (i = 1; i < n; i++) {
       sum = sum + h * y[i];
    }
    return h / 2.0 * (y[0] + y[n]) + sum;
   
}

// f(x) as defined in the specification
double f(double x) {
	double ans;
	ans = ( cos((double)pow((double)x, 2.0)) +(( pow((double)x, 3.0) -2.0* pow((double)x, 2.0) )/10.0));
	return ans;
}

// Used to clear line if input formatting error occurs
void badInput() {
	char junk;
	do{
        scanf("%c", &junk);
    } while (junk != '\n');
}
