/**********************************************
	CS 222: System Programming
	Elizabethtown College
	August Bednar 
    Seamus Corr
	Main file for integration project
	Collects user inputs and calls functions to return values
 ***********************************************/


#include <stdio.h>
#include <math.h>
#include "proj1_functions.h"

int main(){
    double low, hi;
    int n;
    int nRead;
    char cont;
    int isValid;
    double ans;


    do{

        //loop for enpoints user input
        do{
            printf("Enter endpoints of interval to be integrated (low hi): ");
            nRead = scanf("%lf %lf", &low, &hi);

            if (nRead!=2) // User input error
                printf("Error: Improperly formatted input\n\n");
            else if (low>=hi)
                printf("Error: low must be < hi\n\n");

            badInput();

        }while(nRead!=2 || low>=hi);
        
        //loop for numer of trapizoids user input
        do{
            printf("Enter number of trapezoids to be used: ");
            nRead = scanf("%d", &n);
            
            if(nRead!=1){
                printf("Error: Improperly formatted input\n\n");
            } else if (n<1){
                printf("Error: num must be >= 1\n\n");
            }
            
            badInput();

        }while(nRead!=1 || n<1);

        //calculations of trapiziod
        ans = integrate(low, hi, n);
        printf("Using %d trapezoids, integral between %lf and %lf is %lf\n\n", n, low, hi, ans);



        //loop for another interval user input
        do{
        printf("Evaluate another interval (Y/N)? ");
        scanf(" %c", &cont); 
        switch (cont){
            case 'y':
            case 'Y':
                isValid = 1;
                break;
        
            case 'n':
            case 'N':
                isValid = 1;
                return 0;
                break;
        
            default:
                isValid = 0;
                printf("Error: must enter Y or N\n\n");
                break;
        }
        badInput();
        }while(!isValid); 

    } while (cont == 'y' || cont == 'Y');



    return 0;
}