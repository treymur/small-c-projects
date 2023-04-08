/**
 * @file wordle_fun.c
 * @author Trenton Murray
 * @brief wordle functions for main.c (defined at wordle_lib.h)
 * @version 0.1
 * @date 2022-11-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include "wordle_lib.h"


int input(char word[6], char result[6]) {
    printf("Input the word you tried> ");
    scanf("%s", word);
    printf("Input the result> ");
    scanf("%s", result);

    /* Upper-case to lower-case */
    for(int i=0; i<5; i++) { 
        if(word[i]>='A' && word[i]<='Z') {
            word[i] += 'a' - 'A'; // a - A = difference of upper and lower
        }
        if(result[i]>='A' && result[i]<='Z') {
            result[i] += 'a' - 'A';
        }
    } // end of upper -> lower

    /* Validity check */
    if(word[5]) { // checks if '/0' is not at the end of the string (too long)
        return 1;
    }
    if(result[5]) {
        return 2;
    } // end of length check
    for(int i=0; i<5; i++) { // verify input contains letters (or too short)
        if(!(word[i]>='a' && word[i]<='z')){
            return 1;
        }
        if(!(result[i]=='b' || result[i]=='y' || result[i]=='g')) {
            return 2;
        } 
    } // end of vertification
    return 0;
}

void evalue_letter(letter_t *letter, char word[6], char result[6], char f[6]) {
    int blank = 0, yellow = 0, green = 0, maxfreq = 5, minfreq;
    for(int i=0; i<5; i++) { // search each letter for the evaluated letter
        if(word[i] == letter->l) {
            switch(result[i]) {
                case 'b': // if result is blank
                    letter->dne[i] = true;
                    blank += 1;
                    break;
                case 'y': // if result is yellow
                    letter->dne[i] = true;
                    yellow += 1;
                    break;
                case 'g': // if result is green
                    f[i] = letter->l; // put letter in found array
                    green += 1;
                    break;
            } // end of switch (result matching)
        } // end of if (checking if letter)
    } // end of for loop
    minfreq = green + yellow; // must be at least the # of green and yellows
    if(blank > 0) { // if any blanks of the letter, can't have more than shown
        maxfreq = minfreq;
    }
    if(maxfreq < letter->maxf) { // checks if new max is lower than prev max
        letter->maxf = maxfreq;
    }
    if(minfreq > letter->minf) { // checks if new max is higher than prev max
        letter->minf = minfreq;
    }
}

bool word_compare(char word[6], char f[6]) {
    for(int i=0; i<5; i++) {
        if(f[i] && f[i]!=word[i]) { // f[i] checks if there is letter present
            return false;
        }
    }
    return true;
}

bool word_letter_check(char word[6], letter_t letter) {
    int count = 0;
    for(int i=0; i<5; i++) {
        if(word[i]==letter.l) { // when letter is found in word
            if(letter.dne[i] == true) { // check if letter can be in position
                return false;
            }
            count++;
        }
    } // end of for loop
    if(count<letter.minf || count>letter.maxf) { // if letter not in freq bound
        return false;
    }
    return true;
}

