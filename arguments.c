#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc == 2) {
        printf("Hello, %s\n!", argv[1]);
    } else if (argc == 1) {
        printf("Hello, world!\n");
    } else {
        printf("You should just pass your name!!\n");
        return 1;
    }
    return 0;
}
