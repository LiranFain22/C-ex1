//
// Created by Liran on 15/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "PictureManipulation.h"
#define SIZE 3

void fillMatrix(int *matrix){
    int range = 100;
    int min = 1;
    int i,j;

    /* Seed the current time */
    srand(time(NULL));

    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            *(matrix + (i * SIZE) + j)  = rand() % range + min;
        }
    }
}

void printMatrix(const int *matrix){
    int i,j;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            printf("%d ", *(matrix + (i * SIZE) + j));
            if(j == (SIZE - 1)){
                printf("\n");
            }
        }
    }
    printf("\n");
}

void clockwise(int *matrix){
    int i,j;
    for(i = 0; i < SIZE; i++){
        for(j = i; j < SIZE - i - 1; j++){
            // swap elements
            int temp = *(matrix + (i * SIZE) + j);

            // Move values from top to right
              *(matrix + (i * SIZE) + j) = *(matrix + (SIZE * (SIZE - 1 - j)) + i);

            // Move values from right to bottom
              *(matrix + (SIZE *(SIZE - 1 - j)) + i) = *(matrix + (SIZE *(SIZE - 1 - i)) + SIZE - 1 - j);

            // Move values from bottom to left
              *(matrix + (SIZE *(SIZE - 1 - i)) + SIZE - 1 - j) = *(matrix + (SIZE * j) + SIZE - 1 - i);

            // Return temp to left
              *(matrix + (SIZE * j) + SIZE - 1 - i) = temp;
        }
    }
    printf("\n\n--------- picture after manipulation ---------\n");
    printMatrix(matrix);
    makeTurn(matrix);
}

void counterClockwise(int *matrix){
    int i,j;
    for(i = 0; i < SIZE / 2; i++){
        for(j = i; j < SIZE - i - 1; j++){
            //swap elements
              int temp = *(matrix + (SIZE * i) + j);

            // move values from right to top
              *(matrix + (SIZE * i) + j) = *(matrix + (SIZE * j) + SIZE - 1 - i);

            // Move values from bottom to right
              *(matrix + (SIZE * j) + SIZE - 1 - i) = *(matrix + (SIZE * (SIZE - 1 - i)) + SIZE - 1 - j);

            // Move values from left to bottom
              *(matrix + (SIZE * (SIZE - 1 - i)) + SIZE - 1 - j) = *(matrix + (SIZE * (SIZE - 1 - j)) + i);

            // Return temp to left
              *(matrix + (SIZE *(SIZE - 1 - j)) + i) = temp;
        }
    }
    printf("\n\n--------- picture after manipulation ---------\n");
    printMatrix(matrix);
    makeTurn(matrix);
}

void horizontal(int *matrix){
    int i,j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE / 2; j++){
            int temp = *(matrix + (SIZE * j) + i);
            *(matrix + (SIZE * j) + i) = *(matrix + (SIZE * (SIZE - j - 1) + i));
            *(matrix + (SIZE * (SIZE - j - 1) + i)) = temp;
        }
    }
    printf("\n\n--------- picture after manipulation ---------\n");
    printMatrix(matrix);
    makeTurn(matrix);
}

void vertical(int *matrix){
    int i,j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE / 2; j++){
              int temp = *(matrix + (SIZE * i) + j);
              *(matrix + (SIZE * i) + j) = *(matrix + (SIZE * i) + SIZE - j - 1);
              *(matrix + (SIZE * i) + SIZE - j - 1) = temp;
        }
    }
    printf("\n\n--------- picture after manipulation ---------\n");
    printMatrix(matrix);
    makeTurn(matrix);
}

void makeTurn(int *matrix){
    printf("please choose one of the following option\n");
    printf("1 - 90 degree clockwise\n");
    printf("2 - 90 degree counter clockwise\n");
    printf("3 - Flip Horizontal\n");
    printf("4 - Flip Vertical\n");
    printf("-1 - Quit\n");


    int userInput;
    scanf(" %d", &userInput);

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

    fprintf(stderr, "Wrong input, program ending..");
}

void startManipulationGame(){
    int matrix[SIZE][SIZE];

    fillMatrix((int *) matrix);

    printMatrix((int *) matrix);

    makeTurn((int *) matrix);
}
