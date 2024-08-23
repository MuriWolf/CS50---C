#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// pegar os dois inputs do tipo string

// criar um lista com as letras
// criar outra lista com os respectivos valores das letras, então se 'c' vale 1 letras[2], seu respectivo valor na outra lista valores[2], deve valer 3

// criar um loop para cada palavra, que vai verificar seu valor

// mostrar qual é maior

int main(void) {
    string word1 = get_string("Player one: ");
    string word2 = get_string("Player two: ");

    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char values[] = {1, 3, 3, 2, 1,	4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int sumPlayer1 = 0;
    int sumPlayer2 = 0;

    for (int j = 0; j < 26; j++) {
        for (int i = 0; i < strlen(word1); i++) {
            if (toupper(word1[i]) == letters[j]) {
                sumPlayer1 += values[j];
            }
        }
        for (int i = 0; i < strlen(word2); i++) {
            if (toupper(word2[i]) == letters[j]) {
                sumPlayer2 += values[j];
            }
        }
    }

    if (sumPlayer1 > sumPlayer2) {
        printf("Player 1 wins!");
    } else if (sumPlayer1 < sumPlayer2) {
        printf("Player 2 wins!");
    } else {
        printf("Tie!");
    }

}
