/**
 * @file main_dynamic.c
 * @author Trenton Murray
 * @brief Simulates Conway's Game of Life with bad terminal animation
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "conwayGOL.h"

// accepts parameters "inputfile"
int main(int argc, char *argv[]) { 
    int rows, columns;
    bool space[MAX_ROW][MAX_COL];
    /* INPUT */
    if(argc == 1) {
        puts("Welcome to Conway's Game of Life simulator!");
        puts("Note: Press Ctrl + C to exit loop (breakout command)\n");
        char input_file[FILE_MAX];
        printf("Enter the name of input file> ");
        scanf("%s", input_file);
        readtoarr(input_file, space, &rows, &columns);
    } else if (argc == 2) {
        puts("Note: Press Ctrl + C to exit loop (breakout command)\n");
        delay(5000);
        readtoarr(argv[1], space, &rows, &columns);
    } else {
        printf("Error on startup: Invalid number of arguments\n");
        return EXIT_FAILURE;
    } // end of input
    if(!rows || !columns) { // checks if rows or columns are == 0
        printf("Error with input\n");
        return EXIT_FAILURE;
    }

    fprintarr("out.txt", space, rows, columns);
    while(1) {
        delay(500);
        updatearr(space, rows, columns);
        fprintarr("out.txt", space, rows, columns);
    }

    return EXIT_SUCCESS;
}