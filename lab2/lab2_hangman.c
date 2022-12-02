/****************************************************
 Author: August Bednar
 Title: Simple Hangman
 Date: 2/21/2022
 ****************************************************/

// Preprocessor directives
#include <stdio.h>
#include <ctype.h>

// Main function
int main()
{
    /**** V a r i a b l e   D e c l a r a t i o n s ****/

    // Variables for User 1's scanf()
    // Save letters from the given word
    // Initial value is underscore character '_'
    char ltr0 = '_';
    char ltr1 = '_';
    char ltr2 = '_';

    // Masks that indicate whether a letter is matched
    // Zero: letter not matched; non-zero: letter matched.
    int match0 = 0; // Boolean mask for ltr0
    int match1 = 0; // Boolean mask for ltr1
    int match2 = 0; // Boolean mask for ltr2

    // Variable for User 2's scanf()
    // Saves User 2's next guessed letter
    char guess;

    // Return of scanf
    int nRead;

    // Variable used to clear input buffer
    char junk;

    // Flag for the status of the game
    // zero: not winning yet; non-zero: winning
    int won = 0;

    // Loop of input validation for User 1.
    // The only input error is when User 1 enters
    // non-alphabetic characters.

    // loop that prompts for and reads inputs
    // validate input until correctly formated
    do{
        printf("User1, enter a three-letter word: ");
        nRead = scanf("%c%c%c", &ltr0, &ltr1, &ltr2);
        ltr0 = tolower(ltr0);
        ltr1 = tolower(ltr1);
        ltr2 = tolower(ltr2);

        if (!isalpha(ltr0) || !isalpha(ltr1) || !isalpha(ltr2)) // User1 input error
            printf("Error: used non-alphabetic character(s)!\n\n");

        // Mini loop that consumes leftovers from pipe
        do{
            scanf("%c", &junk);
        } while (junk != '\n');

    } while (!isalpha(ltr0) || !isalpha(ltr1) || !isalpha(ltr2));

    // Variables for user 2 letters
    char u2ltr0 = '_';
    char u2ltr1 = '_';
    char u2ltr2 = '_';

    // Loop for User 2 to guess the letters.
    do{
        printf("User2, so far your word is: %c%c%c\n", u2ltr0, u2ltr1, u2ltr2);
        printf("User2, guess a letter: ");
        scanf("%c", &guess);
        guess = tolower(guess);
        if (guess==ltr0){
            u2ltr0=ltr0;
            match0=1;
        } else if (guess==ltr1){
            u2ltr1=ltr1;
            match1=1;
        } else if (guess==ltr2){
            u2ltr2=ltr2;
            match2=1;
        }
        if (match0 && match1 && match2){
            won = 1;
        }
    } while (!won);

    // Print victory message!
    printf("User2 won! The word is %c%c%c.\n", ltr0, ltr1, ltr2);

    return 0;
}