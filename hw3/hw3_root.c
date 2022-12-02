/**********************************************
	CS 222: System Programming
	Elizabethtown College
	August Bednar 
	
    
 ***********************************************/



#include <stdio.h>
double power (double base, int exp)
{
    double result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}



double root(double a, int n){
        double hi= a;
        double low = 0;
        double mid = (hi - low) /2;
        while(hi-low > .000001){
           mid = (hi + low) /2;
            if (power(mid,n)>a){
                hi = mid;
            }
            else{
                low = mid;
            }
        }
    
    return mid;
}

int main(){
    double a;
    int n;
    
    double x = 1;
    int nRead;
    char junk;
    char cont;
    int isValid;


    do{
        do{
            printf("Enter real number and integer (A n): ");
            nRead = scanf("%lf %d", &a, &n);

            if (nRead!=2) // User input error
                printf("Error: Improperly formatted input\n\n");
            else if (a<0)
                printf("Error: value of A must be positive\n\n");
            else if (n<2)
                printf("Error: n must be positive integer >= 2\n\n");

            // Mini loop that consumes leftovers from pipe
            do{
                scanf("%c", &junk);
            } while (junk != '\n');

        }while(nRead!=2 || a<0 || n<2);
        
        
        //DO CALCULATIONS HERE
        x = root(a, n);

        printf("Given A = %.2lf and n = %d, root = %.2lf\n\n", a, n, x);

        do{
        printf("Calculate another root (Y/N)? ");
        scanf(" %c", &cont); 
        switch (cont){
            case 'y':
            case 'Y':
                isValid = 1;
                x = 1;
                break;
        
            case 'n':
            case 'N':
                isValid = 1;
                return 0;
                break;
        
            default:
                isValid = 0;
                printf("Invalid response %c\n\n", cont);
                break;
        }
        // Mini loop that consumes leftovers from pipe
        do{
            scanf("%c", &junk);
        } while (junk != '\n');    
        }while(!isValid); 

    } while (cont == 'y' || cont == 'Y');



    return 0;
}