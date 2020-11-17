//
// Created by Liran on 15/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "NumberGame.h"
#define SIZE 4

///////////////////NumberGame//////////////////////

void matrixGame(){
    int matrix[SIZE][SIZE];

    int upper = 15;
    int lower = 1;

    int i;
    for(i = 0; i < SIZE; i++){
        int j;
        for(j = 0; j < SIZE; j++){
            if(i == (SIZE-1) && j == (SIZE-1))
                matrix[i][j] = 0;
            else{ //////////////// Need to find how too generate numbers WITHOUT duplicate
                matrix[i][j] = (rand() % (upper - lower + 1)) + lower;
            }
        }
    }
}
