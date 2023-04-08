/**
 * @file wordle_lib.h
 * @author Trenton Murray
 * @brief header file for wordle
 * @version 0.1
 * @date 2022-11-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdbool.h>

#define NUM_WORDS 5757

extern char wordlist[NUM_WORDS][6];
// located at word_list.c

/**
 * @brief Information for given letter
 * 
 * @param l char (letter)
 * @param minf int (minimum frequency of letter, default to 0)
 * @param maxf int (maximum frequency of letter, default to 5)
 * @param dne bool[ ] (placement of disproven positions of letter)
 */
typedef struct letter {
    char l;
    int minf;
    int maxf;
    bool dne[5];
} letter_t;

/**
 * @brief Input variables to overwrite with stdin
 * 
 * @param word word that was guessed
 * @param result result of guessed word 
 *               (b for blank, y for yellow, g for green)
 * @return 0 on success; 1 on word input failure; 2 on result input failure
 */
int input(char word[6], char result[6]);

/**
 * @brief Fills out stats for a letter in the letter struct with guessed word
 *        and result, as well as saves found values to an array
 * 
 * @param letter letter_t* (address of letter struct)
 * @param word word that is guessed
 * @param result result of guessed word
 * @param f array with found letters (empty value = '\0')
 */
void evalue_letter(letter_t *letter, char word[6], char result[6], char f[6]);

/**
 * @brief filters word list that match with found letters
 * 
 * @param word word from word list
 * @param f array of found letters with corresponding position
 * @return true when word matches found letters;
 * @return false when word doesn't match found letters
 */
bool word_compare(char word[6], char f[6]);

/**
 * @brief checks if each letter parameters fit in checked word
 * 
 * @param word word from word list
 * @param letter struct of one letter
 * @return true when word works with letter stats
 * @return false when word doesn't work with letter stats
 */
bool word_letter_check(char word[6], letter_t letter);