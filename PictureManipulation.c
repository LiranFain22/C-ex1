//
// Created by Liran on 15/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PictureManipulation.h"
#define SIZE 3

void fillMatrix(int matrix[SIZE][SIZE]){
    int range = 100;
    int min = 1;
    int i,j;

    /* Seed the current time */
    srand(time(NULL));

    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            matrix[i][j] = rand() % range + min;
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE]){
    int i,j;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            printf("%d ", matrix[i][j]);

            if(j == (SIZE - 1)){
                printf("\n");
            }
        }
    }
    printf("\n\n");
}

void clockwise(int matrix[SIZE][SIZE]){}

void counterClockwise(int matrix[SIZE][SIZE]){}

void horizontal(int matrix[SIZE][SIZE]){}

void vertical(int matrix[SIZE][SIZE]){}

void makeTurn(int matrix[SIZE][SIZE]){
    printf("please choose one of the following option\n");
    printf("1 - 90 degree clockwise\n");
    printf("2 - 90 degree counter clockwise\n");
    printf("3 - Flip Horizontal\n");
    printf("4 - Flip Vertical\n");
    printf("-1 - Quit\n");


    int userInput;
    scanf("%d\n", &userInput);

    if(userInput == 1)
        clockwise(matrix);
    if(userInput == 2)
        counterClockwise(matrix);
    if(userInput == 3)
        horizontal(matrix);
    if(userInput == 4)
        vertical(matrix);
    if(userInput == -1)
        main();
}

void startManipulationGame(){

    int matrix[SIZE][SIZE];

    fillMatrix(matrix);

    printMatrix(matrix);

    makeTurn(matrix);
}
