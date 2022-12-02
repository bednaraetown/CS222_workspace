/*
    CS 222: System Programming
	Elizabethtown College
	August Bednar 
	Functions file for Lab 3
	Applies arguments to functions and returns values 
 */

#include <stdio.h>
#include "voting.h"

/********  s h o w C a n d i d a t e s () ********/
/* 
    Arguments: void
    Return: void
    Purpose: prints all candidates on its own line
*/
void showCandidates(void) {
    printf("\n### Available Candidates ###\n\n");
    printf("1. %s\n", CAND1);
    printf("2. %s\n", CAND2);
    printf("3. %s\n", CAND3);
    printf("4. %s\n", CAND4);
}


/**************  c a s t V o t e () ****************/
/* 
    Arguments: int* candCount1, int* candCount2, 
               int* candCount3, int* candCount4
    Return: void
    Purpose: prints the secondary menu, and 
             increments vote count for each candidate
*/
void castVote(int* candCount1, int* candCount2, int* candCount3, int* candCount4){
    int choice;
    int numRead;
    char junk;
    printf("\n### Please Choose Your Candidate ###\n\n");

    do {
        printf("Enter your candidate number (1 - 4): ");
        numRead = scanf("%d", &choice);
        // When input is NOT a number
        /*** COMPLETE THIS CONDITION ***/
        if (numRead!=1) {  
            printf("Error: wrong menu input.\n"); // Report error
            do { // Clear the line
                scanf("%c", &junk);
            } while(junk != '\n');
        }
        
        // When the input is a number
        else { 
            switch(choice){
                case 1:
                *candCount1 = *candCount1 +1;
                printf("Thanks! Vote recorded.\n");
                break;

                case 2:
                *candCount2 = *candCount2 +1;
                printf("Thanks! Vote recorded.\n");
                break;

                case 3:
                *candCount3 = *candCount3 +1;
                printf("Thanks! Vote recorded.\n");
                break;

                case 4:
                *candCount4 = *candCount4 +1;
                printf("Thanks! Vote recorded.\n");
                break;

                default:
                printf("Error: invalid choice.\n");
                do { // Clear the line
                scanf("%c", &junk);
                } while(junk != '\n');
            }
        }

    } while (numRead!=1 || (choice<1||choice>4)); 
}


/**********  d i s p l a y C o u n t ()  ***********/
/* 
    Arguments: int* candCount1, int* candCount2, 
               int* candCount3, int* candCount4
    Return: void
    Purpose: prints the existing vote counts for 
             each candidate on its own line
*/
void displayCount(int* candCount1, int* candCount2, int* candCount3, int* candCount4){
    printf("\n### Voting Count ###\n\n");
    printf("%s - %d\n", CAND1, *candCount1);
    printf("%s - %d\n", CAND2, *candCount2);
    printf("%s - %d\n", CAND3, *candCount3);
    printf("%s - %d\n", CAND4, *candCount4);
}


/*****  l e a d i n g C a n d i d a t e ()  *****/
/* 
    Arguments: int* candCount1, int* candCount2, 
               int* candCount3, int* candCount4
    Return: void
    Purpose: prints only the leading candidate's 
             name based on voting counts; prints
             warning message if no one is winning
*/
void leadingCandidate(int* candCount1, int* candCount2, int* candCount3, int* candCount4){
    printf("\n### Leading Candidate ###\n\n");
    
    if(*candCount1>*candCount2 && *candCount1>*candCount3 && *candCount1>*candCount4){
        printf("%s\n", CAND1);
    }else if(*candCount2>*candCount3 && *candCount2>*candCount4 && *candCount2>*candCount1){
        printf("%s\n", CAND2);
    }else if(*candCount3>*candCount4 && *candCount3>*candCount1 && *candCount3>*candCount2){
        printf("%s\n", CAND3);
    }else if(*candCount4>*candCount1 && *candCount4>*candCount2 && *candCount4>*candCount3){
        printf("%s\n", CAND4);        
    }else{
        printf("Warning: no-win situation.\n");
    }
}