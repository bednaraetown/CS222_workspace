/*
    CS 222: System Programming
	Elizabethtown College
	August Bednar 
	Main file for Lab 3
	Collects user inputs and calls functions to return values
 */

#include <stdio.h>
#include "voting.h"

int main()
{
    /*** Local variable declarations ***/
    int i;              // Counter in for loop
    int choice;         // Menu choices
    int numRead;        // Returned value for scanf
    char junk;          // Handle junk characters in the input stream
    int voteCount1 = 0; // Vote count for candidate 1
    int voteCount2 = 0; // Vote count for candidate 2
    int voteCount3 = 0; // Vote count for candidate 3
    int voteCount4 = 0; // Vote count for candidate 4

    // Main menu that allows:
    // 0. Exit the program
    // 1. Show the candidates
    // 2. Cast the vote
    // 3. Display existing vote counts
    // 4. Find the leading candidate
    do {
        // Print the welcome message
        printf("\n");
        for (i = 0; i < 52; i++)
            printf("-");
        printf("\n###### Vote for the Teaching Excellence Award ######\n");
        for (i = 0; i < 52; i++)
            printf("-");
        printf("\n");

        // Print the menu
        printf("1. Show candidates\n");
        printf("2. Cast the vote\n");
        printf("3. Find vote count\n");
        printf("4. Find leading candidate\n");
        printf("0. Exit\n");

        // Prompt for and read
        printf("\nPlease enter your choice: ");
        numRead = scanf("%d", &choice);
        // Check input format error
        if (numRead != 1)
        {
            printf("Error: wrong menu input.\n");
            do
            {
                scanf("%c", &junk);
            } while (junk != '\n');
        }
        else
        {
            // Operate based on choice
            switch (choice)
            {
                case 1:
                    //show canidates
                    showCandidates();
                    break;
                case 2:
                    //cast the vote
                    castVote(&voteCount1, &voteCount2, &voteCount3, &voteCount4);
                    break;
                case 3:
                    //find vote count
                    displayCount(&voteCount1, &voteCount2, &voteCount3, &voteCount4);
                    break;
                case 4:
                    //find leading canidate
                    leadingCandidate(&voteCount1, &voteCount2, &voteCount3, &voteCount4);
                    break;
                case 0:
                    return 0;
                default:
                    printf("Error: invalid choice.\n");
                    break;

                
                
            }
        }
    } while (numRead != 1 || choice != 0);

    return 0;
}