//
// Created by Liran on 15/11/2020.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "NumberGame.h"
#include "main.h"

#define SIZE 4
#define SHUFFEL_COUNT  10

/**
 * swap 0 with the left cell
 * @param matrix contains the numbers to order
 * @param i the row of 0 location
 * @param j the column of 0 location
 */
void swapLeft(int *matrix, const int i, const int j){
    if((j - 1) >= 0){
        // Swap items
        int temp = *(matrix + (SIZE * i) + j);
        *(matrix + (SIZE * i) + j) = *(matrix + (SIZE * i) + j - 1);
        *(matrix + (SIZE * i) + j - 1) = temp;
        return;
    }
}

/**
 * swap 0 with the top cell
 * @param matrix contains the numbers to order
 * @param i the row of 0 location
 * @param j the column of 0 location
 */
void swapUp(int *matrix, const int i, const int j){
    if((i - 1) >= 0){
        // Swap items
        int temp = *(matrix + (SIZE * i) + j);
        *(matrix + (SIZE * i) + j) = *(matrix + (SIZE * (i - 1)) + j);
        *(matrix + (SIZE * (i - 1)) + j) = temp;
        return;
    }
}

/**
 * swap 0 with the right cell
 * @param matrix contains the numbers to order
 * @param i the row of 0 location
 * @param j the column of 0 location
 */
void swapRight(int *matrix, const int i, const int j){
    if((j + 1) <= (SIZE - 1)){
        // Swap items
        int temp = *(matrix + (SIZE * i) + j);
        *(matrix + (SIZE * i) + j) = *(matrix + (SIZE * i) + j + 1);
        *(matrix + (SIZE * i) + j + 1) = temp;
        return;
    }
}

/**
 * swap 0 with the bottom cell
 * @param matrix contains the numbers to order
 * @param i the row of 0 location
 * @param j the column of 0 location
 */
void swapDown(int *matrix, const int i, const int j){
    if((i + 1) <= (SIZE - 1)){
        // Swap items
        int temp = *(matrix + (SIZE * i) + j);
        *(matrix + (SIZE * i) + j) = *(matrix + (SIZE * (i + 1)) + j);
        *(matrix + (SIZE * (i + 1)) + j) = temp;
        return;
    }
}


/**
 * init board with numbers for 0 to SIZE-1
 * @param matrix the board to fill
 */
void initBoard(int *matrix){
    int i,j;
    int number = 0;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            *(matrix + (SIZE * i) + j) = number;
            number++;
        }
    }
    /* the initial location of 0 */
    i = 0;
    j = 0;
    /* Seed the current time */
    srand(time(NULL));

    /* generate direction for shuffling:
     * 1 - swap 0 with left
     * 2 - swap 0 with up
     * 3 - swap 0 with right
     * 4 - swap 0 with down */
    int direction = rand() % 4 + 1;
    int counter = 0; // count the numbers of board's shuffle

    while(counter < SHUFFEL_COUNT){
        if(direction == 1){
            swapLeft(matrix,i,j);
            if(j>0)
                j--;
        }

        if(direction == 2){
            swapUp(matrix,i,j);
            if(i>0)
                i--;
        }
        if(direction == 3){
            swapRight(matrix,i,j);
            if(j<SIZE-1)
                j++;
        }
        if(direction == 4) {
            swapDown(matrix,i,j);
            if(i<SIZE-1)
                i++;
        }
        direction = rand() % 4 + 1; // generate NEW direction
        counter++;
    }

    /* placing '0' in right bottom corner */
    // swap
    int temp = *(matrix + (i * SIZE) + j);
    *(matrix + (i * SIZE) + j) = *(matrix + (SIZE * (SIZE - 1)) + (SIZE - 1));
    *(matrix + (SIZE * (SIZE - 1)) + (SIZE - 1) ) = temp;
    return;
}

/**
 * print board on screen
 * @param matrix the board to print
 */
void printBoard(int *matrix){
    int i,j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("%d ", *(matrix + (i * SIZE) + j));
            if(j == (SIZE - 1)){
                printf("\n");
            }
        }
    }
    printf("\n");
}

/** check if the board is in-order
 * if return 1 - board is in-order
 * otherwise, 0  - board is NOT in-order */
int checkBoard(const int *matrix){
    int i;
    for(i = 0; i < SIZE; i++){
        if(*(matrix + i) != i)
            return  0;
    }
    return  1;
}

/** this method check if the choose number is valid move and return:
 * 1 - the move is valid
 * 0 - invalid */
int isValidMove(int *matrix, int chooseNumber){
    int i,j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(*(matrix + (i * SIZE) + j) == 0){
                if( j >0 && *(matrix + (i * SIZE) + (j - 1) ) == chooseNumber) {
                    swapLeft(matrix, i, j);
                    return 1;
                }
                if(j<(SIZE-1) && *(matrix + (i * SIZE) + (j + 1) ) == chooseNumber) {
                    swapRight(matrix,i,j);
                    return 1;
                }
                if(i<(SIZE-1) && *(matrix + ((i + 1) * SIZE) + j ) == chooseNumber) {
                    swapDown(matrix,i,j);
                    return 1;
                }
                if(i > 0 && *(matrix + ((i - 1) * SIZE) + (j) ) == chooseNumber) {
                    swapUp(matrix,i,j);
                    return 1;
                }
                return 0;
            }
        }
    }
}

/**
 * make a move by user choice
 * @param matrix the board of the game
 */
void userMove(int *matrix){
    printf("Your step: ");
    int chooseNumber;
    scanf(" %d", &chooseNumber);
    int validMove = isValidMove(matrix, chooseNumber);
    if( validMove == 0){
        printf("Invalid step!\n");
        userMove(matrix);
    }
    if(validMove == 1){
        if(checkBoard(matrix) == 1) {
            printf("You win! The game is over!\n\n");
            main();
        }
        if(checkBoard(matrix) == 0) {
            printBoard(matrix);
            userMove(matrix);
        }
    }
}

/**
 * preparing the board and start the number game
 */
void startNumberGame(){

    int *matrix[SIZE][SIZE];

    initBoard((int *) matrix);

    printBoard((int *) matrix);

    checkBoard((int *) matrix);

    userMove((int *) matrix);
}

