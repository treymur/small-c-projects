/**
 * @file conwayGOL.h
 * @author Trenton Murray
 * @brief Header file for definitions for conwayGOL.c
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdbool.h>

#define MAX_ROW 50
#define MAX_COL 50

#define FILE_MAX 30

/**
 * @brief Delays program for given time (inspired from 
 *        https://www.geeksforgeeks.org/time-delay-c/)
 * 
 * @param duration Time in milliseconds
 */
void delay(unsigned duration);

/**
 * @brief Reads matrix of type bool into given array, file must start with 
 *        amount of rows and columns (use 1 to indicate live space, 0 to
 *        indicate dead space)
 * 
 * @param filename Name of file to read from
 * @param arr Array to receive data from file
 * @param p_rows Variable of the number of rows
 * @param p_cols Variable of the number of columns
 */
void readtoarr(char filename[], bool arr[][MAX_COL], int *p_rows, int *p_cols);

/**
 * @brief Prints array matrix with X's indicating spaces of life
 * 
 * @param arr Bool matrix containing live or dead spaces
 * @param rows Number of rows in matrix
 * @param cols Number of columns in matrix
 */
void printarr(bool arr[][MAX_COL], int rows, int cols);

/**
 * @brief Updates the matrix array according to the rules of the Game of Life
 * 
 * @param arr Bool matrix containing live or dead spaces
 * @param rows Number of rows in matrix
 * @param cols Number of columns in matrix
 */
void updatearr(bool arr[][MAX_COL], int rows, int cols);

/**
 * @brief printarr() but to new file
 * 
 * @param filename Name of new file
 * @param arr Bool matrix containing live or dead spaces
 * @param rows Number of rows in matrix
 * @param cols Number of columns in matrix
 */
void fprintarr(char filename[], bool arr[][MAX_COL], int rows, int cols);