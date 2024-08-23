#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    typedef struct {
        string name;
        string number;
    } person;

    person people[3];

    people[0].name = "Murillo";
    people[0].number = "23423-24324";

    people[1].name = "David";
    people[1].number = "8568565-8656";

    people[2].name = "Kevin";
    people[2].number = "7689-43012";

    string searchedName = get_string("Name: ");

    for (int i = 0; i < 3; i++) {
        if (strcmp(people[i].name, searchedName) == 0) {
            printf("Number founded. %s\n", people[i].number);
            return 0;
        }
    }
    printf("Number not founded.");
    return 1;


}
