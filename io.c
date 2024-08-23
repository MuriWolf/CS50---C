#include <stdio.h>
#include <cs50.h>


int main(void) {
    FILE *file = fopen("phonebook.csv", "a");

    char *name = get_string("type your name: ");
    char *number = get_string("type your number: ");

    fprintf(file, "%s,%s\n", name, number);
    fclose(file);
}
