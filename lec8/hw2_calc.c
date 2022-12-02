/*
Author: August Bednar
Title: A Simple Calculator
Purpose: to read user input and caluclate the result
*/

#include <stdio.h>

int main(){
    int prec; //precision variable
    double calc, a, b, ans;
    char op; //operator variable
    int isValid;
    printf("Enter precision: ");
    scanf("%d", &prec);
    if (prec < 0){
        printf("Error: negative precision");
        return 0;
    }
    // continue to expression
    printf("Enter expression: ");
    isValid = scanf("%lf %c %lf", &a, &op, &b);
    // check valid input
    if (isValid != 3){
        printf("Error: incorrectly formatted input");
        return 0;
    }

    // preform operations
    switch (op){
    case '+':
        printf("\n%.*lf %c %.*lf = ", prec, a, op, prec, b);
        ans = a + b;
        printf("%.*lf", prec, ans);
        break;

    case '-':
        printf("\n%.*lf %c %.*lf = ", prec, a, op, prec, b);
        ans = a - b;
        printf("%.*lf", prec, ans);
        break;

    case '*':
        printf("\n%.*lf %c %.*lf = ", prec, a, op, prec, b);
        ans = a * b;
        printf("%.*lf", prec, ans);
        break;

    case '/':
        if (b == 0){
            printf("Error: cannot divide by 0");
            break;
        }
        printf("%.*lf %c %.*lf = ", prec, a, op, prec, b);
        ans = a / b;
        printf("%.*lf", prec, ans);
        break;

    default:
        printf("Error: invalid operator %c", op);
    }
    return 0;
}