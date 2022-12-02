/*
 * _____________________DO NOT MODIFY THIS FILE________________________
 * File: voting.h
 * Author: Dr. Li
 * Purpose: the header file that declares macros and function prototypes
 */

#ifndef VOTING_H
#define VOTING_H

/*** Define all the macros (constants) ***/
#define CAND1 "Dr. Leap"
#define CAND2 "Dr. Wunderlich"
#define CAND3 "Dr. Wang"
#define CAND4 "Dr. Li"

/*** Function prototypes ***/
void showCandidates(void);
void castVote(int* candCount1, int* candCount2, int* candCount3, int* candCount4);
void displayCount(int* candCount1, int* candCount2, int* candCount3, int* candCount4);
void leadingCandidate(int* candCount1, int* candCount2, int* candCount3, int* candCount4);

#endif