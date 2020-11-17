#include <stdio.h>
#include "PictureManipulation.h"
#include "NumberGame.h"
#define MATRIX_SIZE 3

void main() {
    printf("Please choose one of the following options \n");

    printf("P/p - Picture Manipulation \n");
    printf("N/n - Number Game \n");
    printf("E/e - Quit \n");

    char input;

    scanf("%c", &input);


    if( input == 'P' || input == 'p' ){
        //here we need to move to 'Picture Manipulation'
        startManipulationGame();
    }
    if( input == 'N' || input ==  'n'){
        //here we need to move to 'Number Game'
    }
    if( input == 'E' || input == 'e' ){
        printf("Bye bye");
    }
}

