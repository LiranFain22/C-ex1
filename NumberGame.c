//
// Created by Liran on 15/11/2020.
//

#include <stdlib.h>
#include <time.h>
#include "NumberGame.h"

#define SIZE 4
#define SHUFFEL_COUNT  10

void swapLeft(int *matrix){
    int i,j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(*(matrix + (SIZE * i) + j) == 0){
                if((j - 1) >= 0){
                    // Swap items
                    int temp = *(matrix + (SIZE * i) + j);
                    *(matrix + (SIZE * i) + j) = *(matrix + (SIZE * i) + j - 1);
                    *(matrix + (SIZE * i) + j - 1) = temp;
                }
            }
        }
    }
}

void swapUp(int *matrix){
    int i,j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(*(matrix + (SIZE * i) + j) == 0){
                if((i - 1) >= 0){
                    // Swap items
                    int temp = *(matrix + (SIZE * i) + j);
                    *(matrix + (SIZE * i) + j) = *(matrix + (SIZE * (i - 1)) + j);
                    *(matrix + (SIZE * (i - 1)) + j) = temp;
                }
            }
        }
    }
}

void swapRight(int *matrix){
    int i,j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(*(matrix + (SIZE * i) + j) == 0){
                if((j + 1) <= (SIZE - 1)){
                    // Swap items
                    int temp = *(matrix + (SIZE * i) + j);
                    *(matrix + (SIZE * i) + j) = *(matrix + (SIZE * i) + j + 1);
                    *(matrix + (SIZE * i) + j + 1) = temp;
                }
            }
        }
    }
}

void swapDown(int *matrix){
    int i,j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(*(matrix + (SIZE * i) + j) == 0){
                if((i + 1) <= (SIZE - 1)){
                    // Swap items
                    int temp = *(matrix + (SIZE * i) + j);
                    *(matrix + (SIZE * i) + j) = *(matrix + (SIZE * (i + 1)) + j);
                    *(matrix + (SIZE * (i + 1)) + j) = temp;
                }
            }
        }
    }
}

void initBoard(int *matrix){
    int i,j;
    int number = 0;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            *(matrix + (SIZE * i) + j) = number;
            number++;
        }
    }

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
        if(direction == 1)
            swapLeft(matrix);
        if(direction == 2)
            swapUp(matrix);
        if(direction == 3)
            swapRight(matrix);
        if(direction == 4)
            swapDown(matrix);

        direction = rand() % 4 + 1; // generate NEW direction
        counter++;
    }
}

void startNumberGame(){
    int *matrix[SIZE][SIZE];

    initBoard((int *) matrix);
}

