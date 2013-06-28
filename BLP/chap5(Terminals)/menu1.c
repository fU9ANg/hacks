#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *menu[] = {
    "a − add new record",
    "d − delete record",
    "q − quit",
    NULL,
};

int getchoice(char *greet, char *choices[]);

int main()
{
    int choice = 0;
    do
    {
        choice = getchoice("Please select an action", menu);
        printf("You have chosen: %c\n", choice);
    } while(choice != 'q');

    exit(0);
}

int getchoice(char *greet, char *choices[])
{
    int chosen = 0;
    int selected;
    char **option;
    do {
        printf("Choice: %s\n",greet);
        option = choices;
        while(*option) {
            printf("%s\n",*option);
            option++;
        }
        selected = getchar();
        option = choices;
        while(*option) {
            if(selected == *option[0]) {
                chosen = 1;
                break;
            }
            option++;
        }

        if(!chosen) {
            printf("Incorrect choice, select again\n");
        }
    } while(!chosen);

    return selected;
}

#if 0
$ menu1
Choice: Please select an action
a − add new record
d − delete record
q − quit
a
You have chosen: a
Choice: Please select an action
a − add new record
d − delete record
q − quit
Incorrect choice, select again
Choice: Please select an action
a − add new record
d − delete record
q − quit
q
You have chosen: q
$
#endif
