#include <stdio.h>
double pow (double base, int exp)
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

double abs(double x){
    if(x<0){
        return x*-1;
    }
    else return x;
}

/*
double calcroot(double x, double n, double prev){
    double part1 = 1/n;
    double part2 = (n-1)*prev;
    double part3 = x/pow(prev,n-1);
    double part4 = (part2)+(part3);

    double root = part1 * abs(part4);
        double  = 1/n * abs(((n-1)*prev) + (x/(pow(prev,n-1))));

        return root;
    }
double calcdeciroot(double x, double n){
    // turn decimal into appropriate int to do root calc ex 0.759 -> 759
    // idea was to use multiply by 10 then check modulus = 0 but cant modulus a double/float :(
    double num = x;
    int intnum;
    intnum = num * 10000000;

    do{
        intnum = intnum/10;
    }while(intnum%10 != 0  );
    double result = calcroot(num, n, 1);
}
*/

double nthroot(double number, int n){
        double hi= number;
        double low = 0;
        double mid = (hi - low) /2;
        while(hi-low > .000001){
           mid = (hi + low) /2;
            if (pow(mid,n)>number){
                hi = mid;
            }
            else{
                low = mid;
            }
        }
    
    return mid;
}

double LessThan_One(double number, int n){


// find number of decimal places
double x = number;
int count;
int trunc;

/*while(trunc<x){
    trunc++;
}
trunc--;
*/

while (number*10>0){
    x = x*10;
    trunc = x;
    x = x - trunc;
    if(x<.000001){ // checks because when x = x-trunc double will have tiny decimal number attached at the end that never lets it be 0
        count++;
        break;
    }
    count++;
    
}




    double num = number *(pow(10.0,count));

    double convert = pow(10,count);

    double deciroot = nthroot(num, n)/nthroot(convert,n);

   return deciroot;
}


    

int main(){
    char response ='N';
    do{
    double A;
    int n;
    double root;
    double aprox;
    double prevroot;
    int base = 0;
    int guess;
    double diff;

    printf("Enter real number and integer (A n): \n");
    scanf("%lf %d", &A, &n);

    if(A<0){
        printf("Error: value of A must be positive \n");
    }

    if(n<2){
        printf("Error: n must be positive integer >= 2 \n");
    }

   
    if(A<1){
    root = LessThan_One(A,n);
    }
    else{
    root = nthroot(A,n);
    }
    

    printf("Given A = %.2lf and n = %d, root = %.2lf \n", A, n, root);

        printf("Calulate another root (Y/N)? \n");
        scanf(" %c", &response);
        

    }while(response !='N');
    }

    // guess by finding what number to the power of the root gets closest to the base without going over










/*
    int x;
    
    
    do{
        x = pow(base,n);
    if(A>x){
        base++;
    }
    if(A<x){
    base--;
    }
    if(A==x){
        break;
    }

    if(A<1){
        break;
    }
        } while (x<A);

    if(A == pow(base,n)){
        guess = base;
    }
    if(A < 1){
        root = calcdeciroot(A, n);
        guess =1;
    }
    
    root =calcroot(A,n,guess);

    do{
        prevroot = root;
        root =calcroot(A,n,prevroot);
        diff = root - prevroot;
    }while( diff >.000001);
*/
