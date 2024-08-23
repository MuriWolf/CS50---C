#include <stdio.h>
#include <cs50.h>

int main(void) {
    string text = "murillo";

    int n = 0;
    while (text[n] != '\0') {
        n++;
    }
    printf("%i\n", n);
    printf("%c%c%c%i\n", text[0], text[1], text[2], text[3]);
}
