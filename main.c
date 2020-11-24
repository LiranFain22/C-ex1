#include <stdio.h>
#include "PictureManipulation.h"
#include "NumberGame.h"

int main() {
    printf("Please choose one of the following options \n");

    printf("P/p - Picture Manipulation \n");
    printf("N/n - Number Game \n");
    printf("E/e - Quit \n");

    char input;

    scanf(" %c", &input);

    switch (input) {
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
            fprintf(stderr, "Wrong input, program ending..");
            break;
    }
}

