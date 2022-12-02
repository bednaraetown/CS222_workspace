/*************************************************
    CS 222: System Programming
	Elizabethtown College
	August Bednar 
    Simon Burleson
	Functions source file for histogram project 
    ***************************************************/

#include <stdio.h>
#include <ctype.h>
#include "proj2_functions.h"

/* Function Definitions */

/* Reads single line of text and updates histogram
 as well as frequency of most frequent letter */
void readText(int histo[], int *max) {
    char inChar;        // Character input
    int index;          // Index into histogram
    scanf("%c", &inChar);

    do{
        
        scanf("%c", &inChar);
        if(isalpha(inChar)!=0){
            index = toupper(inChar)-65;
            histo[index]++;
            if(histo[index]>*max)
                *max = histo[index];
        }
    }while (inChar!= '\n');
    
/*
    // Clear the line, then repeatedly
    //   read characters and update histogram
    do{
            scanf("%c", &junk);
        }while(junk!='\n');
    printf("ENTER A LINE OF TEXT:\n\n");
    scanf("  %[^\n]", input);
    
    //csize = sizeof input / sizeof *input;
    for(i = 0; i<sizeof(input)-2; i++){
        if(isalpha(input[i])!=0){
            input[i] = toupper(input[i]);
            histo[input[i]-65] += 1;

        }
    }

    //loop to check most frequent letter
    *max = histo[0];
    for(i = 1; i<26; i++){
        if(histo[i]>*max ){
            *max = histo[i];
        }
    }
    */
}

/* Prints histogram, using array holding values
 as well as frequency of most frequent letter,
 which determines height of histogram */
void drawHist(int histo[], int max) {
    int i, j;        // Loop indices

    // Print histogram with max rows, 26 columns
    //   Must start at top and work way down
    printf("LETTER FREQUENCIES IN TEXT:\n\n");
    for(i = max; i>0; i--){
        for(j=0; j<26; j++){
            if(histo[j] >=i){
                printf("| ");
                //histo[j] = histo[j]-1;
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
   
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z \n");
    printf("\n");
 }



