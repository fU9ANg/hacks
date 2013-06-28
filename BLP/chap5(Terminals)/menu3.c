#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *menu[] = {
    "a − add new record",
    "d − delete record",
    "q − quit",
    NULL,
};

int getchoice(char *greet, char *choices[], FILE *in, FILE *out);

int main()
{
    int choice = 0;
    FILE *input;
    FILE *output;

    if(!isatty(fileno(stdout))) {
        fprintf(stderr,"You are not a terminal, OK.\n");
    }

    input = fopen("/dev/tty", "r");
    output = fopen("/dev/tty", "w");
    if(!input || !output) {
        fprintf(stderr,"Unable to open /dev/tty\n");
        exit(1);
    }

    do {
        choice = getchoice("Please select an action", menu, input, output);
        printf("You have chosen: %c\n", choice);
    } while(choice != 'q');
    exit(0);
}

int getchoice(char *greet, char *choices[], FILE *in, FILE *out)
{
    int chosen = 0;
    int selected;
    char **option;

    do {
        fprintf(out,"Choice: %s\n",greet);
        option = choices;
        while(*option) {
            fprintf(out,"%s\n",*option);
            option++;
        }

        do {
            selected = fgetc(in);
        } while(selected == '\n');

        option = choices;

        while(*option) {
            if(selected == *option[0]) {
                chosen = 1;
                break;
            }
            option++;
        }

        if(!chosen) {
            fprintf(out,"Incorrect choice, select again\n");
        }
    } while(!chosen);

    return selected;
}

#if 0
program output is separated:
$ menu3 > file
You are not a terminal, OK.
Choice: Please select an action
a − add new record
d − delete record
q − quit
d
Choice: Please select an action
a − add new record
d − delete record
q − quit
q
$ cat file
You have chosen: d
You have chosen: q
#endif
