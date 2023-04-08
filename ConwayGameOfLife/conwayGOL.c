/**
 * @file conwayGOL.c
 * @author Trenton Murray
 * @brief Functions used to simulate Conway's game of life in a terminal
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "conwayGOL.h"


void delay(unsigned duration) {
    clock_t start = clock(); // sets start to when function called
    while(clock() < (start + duration));
}

void readtoarr(char filename[], bool arr[][MAX_COL], int *p_rows, int *p_cols) {
    FILE *inp = fopen(filename, "r");
    if(!inp) { // checks if inp is NULL
        perror("Error opening file");
        *p_rows = 0;
        *p_cols = 0;
    } else {
        fscanf(inp, "%d %d", p_rows, p_cols);
        int i, j; // counting variables
        for(i=0; i<*p_rows; i++) {
            for(j=0; j<*p_cols; j++) {
                fscanf(inp, "%d", &arr[i][j]);
            }
        }
    }
    fclose(inp);
}

void _print_line(int width) {
    for(int i=0; i<width; i++) {
        printf("+---");
    }
    puts("+");
}

void printarr(bool arr[][MAX_COL], int rows, int cols) {
    int i, j; // counting variables
    for(i=0; i<rows; i++) {
        _print_line(cols);
        for(j=0; j<cols; j++) {
            if(arr[i][j]) printf("| X "); // if space is live
            else          printf("|   "); // if space is dead
        }
        puts("|");
    }
    _print_line(cols);
    puts("\n");
}

void updatearr(bool arr[][MAX_COL], int rows, int cols) {
    bool buff[MAX_ROW][MAX_COL];
    int i, j; // counting variables
    bool n, ne, e, se, s, sw, w, nw; // temporary cardinal directions
    int adjacent; // temporary adjacent counter
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            /* CHECK IF ON EDGE (and find value of cardinal directions) */
                /* Find north value */
                if(i == 0)      n = false;       // can't look up
                else            n = arr[i-1][j]; // can look up
                /* Find south value */
                if(i == rows-1) s = false;       // can't look down
                else            s = arr[i+1][j]; // can look down
                /* Find west value */
                if(j == 0)      w = false;       // can't look left
                else            w = arr[i][j-1]; // can look left
                /* Find east value */
                if(j == cols-1) e = false;       // can't look right
                else            e = arr[i][j+1]; // can look right

                /* Find northwest value */
                if(i==0 || j==0)           nw = false;
                else                       nw = arr[i-1][j-1];
                /* Find northeast value */
                if(i==0 || j==cols-1)      ne = false;
                else                       ne = arr[i-1][j+1];
                /* Find southwest value */
                if(i==rows-1 || j==0)      sw = false;
                else                       sw = arr[i+1][j-1];
                /* Find southeast value */
                if(i==rows-1 || j==cols-1) se = false;
                else                       se = arr[i+1][j+1];
            /* END OF EDGE CHECK */
            adjacent = n + ne + e + se + s + sw + w + nw;
            if(adjacent==3) { // always live when 3 adjacent spaces
                buff[i][j] = true;
            } else if (arr[i][j]==true && adjacent==2) { // live spaces remain
                buff[i][j] = true;
            } else {
                buff[i][j] = false; // dead from under or over population
            }
        }
    }

    /* Replace matrix */
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            arr[i][j] = buff[i][j];
        }
    }
}

void _fprint_line(FILE *file, int width) {
    for(int i=0; i<width; i++) {
        fputs("+---", file);
    }
    fputs("+\n", file); // ensures there is width != 0
}

void fprintarr(char filename[], bool arr[][MAX_COL], int rows, int cols) {
    FILE *outp = fopen(filename, "w");
    int i, j; // counting variables
    for(i=0; i<rows; i++) {
        _fprint_line(outp, cols);
        for(j=0; j<cols; j++) {
            if(arr[i][j]) fputs("| O ", outp); // if space is live
            else          fputs("|   ", outp); // if space is dead
        }
        fputs("|\n", outp);
    }
    _fprint_line(outp, cols);
    fputs("\n\n", outp);
    fclose(outp);
}