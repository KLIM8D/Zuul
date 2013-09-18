#include "include/Command.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *commands[] = {"go", "help", "quit", "rooms"};
#define NELEMENTS sizeof(commands) / sizeof(commands[0])

int processCommand(command *cmd, room **roomp)
{
    char *word = cmd->firstWord;

    if (strcmp(word, "help") == 0)
        printHelp();
    else if(strcmp(word,"go") == 0) {
        goRoom(roomp);
        printf("%s\n", (*roomp)->name);
    }
    else if(strcmp(word, "rooms") == 0)
        printRoomExists(*roomp);
    else if (strcmp(word, "quit") == 0)
        return 0;
    else {
        printf("Unknown command\n");
        printHelp();
    }

    return 1;
}

void printHelp(void)
{
    printf("You are lost. You are alone. You wander\n");
    printf("around at the university.\n");
    printf("Your command words are:\n");
    int i;
    for (i = 0; i < NELEMENTS; ++i)
        printf("%s\n", commands[i]);
}

struct command *getCommand(command *cmd)
{
    char line[100];
    int maxLine = 100;
    char spacer[] = " ";
    printf("C: ");
    getLine(line, maxLine);

    cmd->firstWord = strtok(line, spacer);
    cmd->secondWord = strtok(NULL, spacer);

    /*free(line);*/
    return cmd;
}

/* getline: get line into s, return length */
int getLine(char *s, int limit)
{
    int c, i;

    i = 0;
    while (--limit && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    
    /*if(c == '\n')
        s[i++] = c;*/
    s[i] = '\0';

    return i;
}

void goRoom(room **roomp)
{
    *roomp = (*roomp)->nextRoom;
    printf("Current room: %s\n", (*roomp)->name);
}

void printRoomExists(room *roomp)
{
    printf("Exits:\n");
    printf("%s\n", roomp->nextRoom->name);
}
