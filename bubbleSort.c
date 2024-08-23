#include <stdio.h>

int main(void) {
    int array[] = {9, 1, 4, 2, 3, 8, 6, 7, 5};
    int arrayLength = 9;

    for (int i = 0; i < arrayLength -1; i++) {
        for (int j = 0; j < arrayLength - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
