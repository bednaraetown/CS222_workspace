/*
Author August Bednar
Date: 2/2/2022
Description: circuit analysis
*/

#include <stdio.h>

int main() {
    double volt;
    double res1, res2, res3;

    printf("Enter voltage source value (V): ");
    scanf("%lf", &volt);
    printf("Enter three resistance values (ohms): ");
    scanf("%lf %lf %lf", &res1, &res2, &res3);
    

    //calculate SERIES CIRCUIT
    double serVolt;
    double serRes1, serRes2, serRes3;
    serVolt = volt/(res1+res2+res3);
    serRes1 = serVolt*res1;
    serRes2 = serVolt*res2;
    serRes3 = serVolt*res3;
    //output for SERIES CIRCUIT
    printf("\nSERIES CIRCUIT\n");
    printf("Current through circuit: %lf A\n", serVolt);
    printf("Voltage across R1: %lf V\n", serRes1);
    printf("Voltage across R2: %lf V\n", serRes2);
    printf("Voltage across R3: %lf V\n", serRes3);

    
    //calculation and output for PARALLEL CIRCUIT
    printf("\nPARALLEL CIRCUIT\n");
    printf("Voltage across each resistor: %lf V\n", volt);
    printf("Current through R1: %lf A\n", volt/res1);
    printf("Current through R2: %lf A\n", volt/res2);
    printf("Current through R3: %lf A\n", volt/res3);


    //calculate R2 & R3 IN PARALLEL
    double req, i, Veff; //R equivilent, I, V effective
    req = (res2 * res3)/(res2 + res3);
    i = volt / (res1 + req);
    Veff = i*req;

    //output for R2 & R3 IN PARALLEL
    printf("\nR2 & R3 IN PARALLEL\n");
    printf("Voltage across R1: %lf V\n", i*res1);
    printf("Current through R1: %lf A\n", i);
    printf("Voltage across R2: %lf V\n", Veff);
    printf("Current through R2: %lf A\n", Veff/res2);
    printf("Voltage across R3: %lf V\n", Veff);
    printf("Current through R3: %lf A\n", Veff/res3);

    return 0;
}
