#include <stdio.h>

void showNum(int *pNum) {
    printf("the value of %p is %i\n", pNum, *pNum);
}

int main(void) {
    int num = 21;
    int *pNum = NULL;
    pNum = &num;

    printf("addres value of %i is %p\n", num, pNum);

    showNum(pNum);
}
