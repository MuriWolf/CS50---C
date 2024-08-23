#include <stdio.h>
#include <string.h>
// #include <cs50.h>

int main(void) {
    char text[] = "murillo";

    for (int i = 0, length = strlen(text); i < length; i++) {
        printf("%c", text[i] - 32);
    }
    printf("\n");
}
