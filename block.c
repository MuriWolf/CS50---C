#include <stdio.h>
#include <cs50.h>

void createBlock(void);

int main(void) {
    // creates a loop for the rows, and inside each repetition, creates the columns

    createBlock();
}

void createBlock(void) {
    int number;

    do {
        number = get_int("Type an integer: ");
    } while (number < 1);

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("#");
        }
        printf("\n");
    }
}
