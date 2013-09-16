#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED
typedef struct command {
    char *firstWord;
    char *secondWord;
}command;

int isUnknown(void);
int hasSecondWord(void);
#endif
