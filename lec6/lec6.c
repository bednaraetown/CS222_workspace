#include <stdio.h>
int main()
{
    /*
    int x;
    printf("Enter for x:");
    scanf("%d", &x);
    if(x>5 &&x <=10)
        printf("%d\n", x);


    double temp;
    printf("Enter temperature: ");
    scanf("%lf", &temp);
    if(temp>=90)
        printf("It's too hot!\n");
    else if (temp<=32)
        printf("It's freezing!\n");
     else
        printf("It's okay\n");
    */
    int numRead;
    int num1, num2, num3;
   
    printf("Enter 3 seprate values: ");
    numRead = scanf("%d %d %d", &num1, &num2, &num3);
    if(numRead<3)
        printf("Error: only %d inputs read correctly\n", numRead);
    else
        printf("%d numbers detected!\n", numRead);
    return 0;
}