/**
 * @file main_static.c
 * @author Trenton Murray
 * @brief Simulates Conway's game of life for an entered number of iterations
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

// accepts parameters "inputfile", "number of iterations"
int main(int argc, char **argv) { 
    int rows, columns, num; // number of iterations to simulate
    bool space[MAX_ROW][MAX_COL];
    /* INPUT */
    if(argc == 1) {
        puts("Welcome to Conway's Game of Life simulator!\n");
        char input_file[FILE_MAX];
        printf("Enter the name of input file> ");
        scanf("%s", input_file);
        printf("Number of iterations> ");
        scanf("%d", &num);
        readtoarr(input_file, space, &rows, &columns);
    } else if (argc == 3) {
        char *excess; // contains excess non-number input of argv[2]
        num = (int)strtol(argv[2], &excess, 10);
        readtoarr(argv[1], space, &rows, &columns);
    } else {
        printf("Error on startup: Invalid number of arguments\n");
        return EXIT_FAILURE;
    } // end of input
    if(!rows || !columns) { // checks if rows or columns are == 0
        printf("Error with input\n");
        return EXIT_FAILURE;
    }

    printarr(space, rows, columns);
    for(int i=0; i<num; i++) {
        updatearr(space, rows, columns);
        puts("\n");
        printarr(space, rows, columns);
    }

    return EXIT_SUCCESS;
}