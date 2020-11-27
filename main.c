#include <stdio.h>
#include "PictureManipulation.h"
#include "NumberGame.h"


char getUserMove() {
    printf("Please choose one of the following options \n");

    printf("P/p - Picture Manipulation \n");
    printf("N/n - Number Game \n");
    printf("E/e - Quit \n");

    char input;

    scanf(" %c", &input);
    return input;
}

int main() {
    switch (getUserMove()) {
        case 'P':
            startManipulationGame();
            break;
        case 'p':
            startManipulationGame();
            break;
        case 'N':
            startNumberGame();
            break;
        case 'n':
            startNumberGame();
            break;
        case 'E':
            printf("Bye Bye");
            break;
        case  'e':
            printf("Bye Bye");
            break;
        default:
            fprintf(stderr, "Wrong input, program ends..");
            break;
    }
}

