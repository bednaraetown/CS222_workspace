#include "lec11_functions.h"
#include <stdio.h>

//Function Prototypes
void printSquare(int length){
    int i, j;
    for(i=0;i<length;i++){
        for(j=0; j<length;j++){
            printf("*");
        }        
        printf("%c", "\n");
    }
}

int checkEvenOdd(void){
    int input;
    printf("Enter an integer: ");
    scanf("%d", &input);
    if(input%2==0){
        //even
        return 1;
    }else {
        //odd
        return 0;
    }       
}

double avgFour(double num1, double num2, double num3, double num4){
    double sum, mean;
    sum = num1 + num2 + num3 + num4;
    mean = sum/4.0;
    return mean;
}