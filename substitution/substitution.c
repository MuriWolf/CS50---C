#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool validateKey(string key);

int main(int argc, string argv[]) {
    if (argc > 2 || argc == 1) {
        printf("Should have one and only one argument.\n");
        return 1;
    } else {
        string key = argv[1];
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        if (!validateKey(key)) {
            return 1;
        }

        string toIncript = get_string("Plaintext: ");
        string incripted = toIncript;

        for (int i = 0; i < strlen(toIncript); i++) {
            if (isalpha(toIncript[i])) {
                for (int j = 0; j < strlen(letters); j++) {
                    if (toupper(toIncript[i]) == letters[j]) {
                        if (isupper(toIncript[i])) {
                            incripted[i] = toupper(key[j]);
                        } else {
                            incripted[i] = tolower(key[j]);
                        }
                        break;
                    }
                }
            }
        }
        printf("ciphertext: %s\n", incripted);
        return 0;
    }
}


bool validateKey(string key) {
    if (strlen(key) < 26 || strlen(key) > 26) {
        printf("Key should contain 26 characteres!");
        return false;
    } else {
        for (int i = 0; i < strlen(key); i++) {
            if (!isalpha(key[i])) {
                return false;
            }
            for (int j = 0, countLetter = 0; j < strlen(key); j++) {
                if (toupper(key[i]) == toupper(key[j])) {
                    countLetter++;
                }
                if (countLetter > 1) {
                    return false;
                }
            }
        }
    return true;
    }
}
