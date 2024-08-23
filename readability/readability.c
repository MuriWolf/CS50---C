#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    string text = get_string("Enter the text: ");

    int countLetters = 0;
    int countWords = 1;
    int countSentenses = 0;

    for (int i = 0; i < strlen(text); i ++) {
        if (toupper(text[i]) >= 65 && toupper(text[i]) <= 90) {
            countLetters++;
        } else if (isblank(text[i])) {
            countWords++;
        } else if (text[i] == '?' || text[i] == '!' || text[i] == '.') {
            countSentenses++;
        }
    }
    float index = 0.0588 * (( (float) countLetters / (float) countWords) * 100.0) - 0.296 * (( (float) countSentenses / (float) countWords) * 100.0) - 15.8;
    int roundedIndex = round(index);

    if (index == 1 || index < 1) {
        printf("Before Grade 1\n");
    } else if (index >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", roundedIndex);
    }
}
