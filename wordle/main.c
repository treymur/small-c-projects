/**
 * @file main.c
 * @author Trenton Murray
 * @brief Finds all possible words left in wordle with given words and results
 * @version 0.1
 * @date 2022-11-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include "wordle_lib.h"


int main() {
    /* DECLARATIONS */
    char wordIn[6], resultIn[6]; // input word and result
    int status; // input declarations
    char found[6] = {0}; // array containing found letters
    bool posWord[NUM_WORDS]; // bool list corresponding to word list
    for(int i=0; i<NUM_WORDS; i++) { // fill with trues
        posWord[i] = true;
    }
    int count = 2; // counting var for number of answers

    letter_t letters[26]; // struct for stats for each letter
    for(int i=0; i<26; i++) {
        letters[i].l = 'a' + i;
        letters[i].minf = 0;
        letters[i].maxf = 5;
        for(int j=0; j<5; j++) {
            letters[i].dne[j] = false;
        }
    }
    while(count > 1) {
        /* INPUT */
        while(status = input(wordIn, resultIn)) { // set status to error value
            if(status == 1) {
                printf("\nError in word input\n");
            }
            if(status == 2) {
                printf("\nError in result input\n");
            }
        }

        /* EVALUATE STATS OF LETTERS */
        for(int i=0; i<26; i++) {
            evalue_letter(&letters[i], wordIn, resultIn, found);
        }

        /* FILTER WORD LIST (with the bool array) */
        for(int i=0; i<NUM_WORDS; i++) {
            if(!word_compare(wordlist[i], found)) { // if word doesn't match found[]
                posWord[i] = false;
            }
            for(int j=0; j<26 && posWord[i]; j++) { // checks each letter
                if(!word_letter_check(wordlist[i], letters[j])) {
                    posWord[i] = false;
                }
            } // end of for loop (letter check)
        } // end of for loop (filter)
        
        /* PRINT LIST */
        count = 0;
        for(int i=0; i<NUM_WORDS; i++) {
            if(posWord[i]) { // if value works, print it
                printf(" %s\n", wordlist[i]);
                count++;
            }
        }
    } // end of while loop
    return 0;
}