#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    long number = get_long("Enter a credit card number: ");

    int i = 1;
    int sum = 0;
    int firstDigits = 0;
    while (number != 0) {
        int restNumber = number % 10;
        if (i % 2 == 0) {
            int unity = (restNumber * 2) % 10;
            int decimal = ((restNumber * 2) - unity) / 10;
            sum = sum + decimal + unity;
        } else {
            sum = sum + restNumber;
        }
        i++;
        number = floor(number / 10);
        if (number < 100 && number > 9) {
            firstDigits = number;
        }
    }
    if (sum % 10 == 0) {
        if ((firstDigits / 10 % 10 == 4) && (i-1 == 16 || i-1 == 13)) {
            printf("VISA\n");
        } else if ((firstDigits == 51 || firstDigits == 52 || firstDigits == 53 || firstDigits ==  54 || firstDigits == 55) && (i-1 == 16)) {
            printf("MASTERCARD\n");
        } else if ((firstDigits == 34 || firstDigits == 37) && (i-1 == 15)) {
            printf("AMEX\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
}
