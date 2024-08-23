#include "stdio.h"
#include "cs50.h"

int main(void) {
    int x = get_int("type x: ");
    int y = get_int("type y: ");

    if (x < y) {
        printf("x is less than y.\n");
    }
}
