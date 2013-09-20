#include "include/Command.h"
#include "include/Dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char **commands;
#define NELEMENTS 4

void initCommands(void)
{
    commands = malloc(NELEMENTS * sizeof(char*));
    commands[0] = "go";
    commands[1] = "help";
    commands[2] = "quit";
    commands[3] = "rooms";
}

int processCommand(command *cmd, room **roomp)
{
    if(cmd->firstWord == NULL) {
        putchar('\n');
        return 0;
    }

    if (strcmp(cmd->firstWord, "help") == 0)
        printHelp();
    else if(strcmp(cmd->firstWord,"go") == 0) {
        goRoom(roomp, cmd->secondWord);
        printf("Current room: %s\n", (*roomp)->name);
    }
    else if(strcmp(cmd->firstWord, "rooms") == 0)
        printRoomExists(*roomp);
    else if (strcmp(cmd->firstWord, "quit") == 0)
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

struct command *getCommand(char *line, command *cmd)
{
    int maxLine = 100;
    char spacer[] = " ";
    printf("\ncmd: ");
    getLine(line, maxLine);

    cmd->firstWord = strtok(line, spacer);
    cmd->secondWord = strtok(NULL, spacer);

    return cmd;
}

/* getline: get line into s, return length */
int getLine(char *s, int limit)
{
    int c, i;

    i = 0;
    while (--limit && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

void goRoom(room **roomp, char *secondWord)
{
    int i = getDirectionIndex(secondWord);
    if(i >= 0) {
        if(((*roomp)->nextRoom[i]) != NULL)
            **roomp = *((*roomp)->nextRoom[i]);
        else
            printf("No door to the %s\n", secondWord);
    }
    else
        printf("Unknown room\n");
}

void printRoomExists(room *roomp)
{
    printf("Exits:\n");
    int i;
    for(i = 0; i < 4; ++i)
        if(roomp->nextRoom[i] != NULL)
            printf("%s: %s\n", getDirection(i), roomp->nextRoom[i]->name);
}

char *getDirection(int i)
{
    switch(i) {
        case 0:
            return "East";
        case 1:
            return "North";
        case 2:
            return "West";
        case 3:
            return "South";
        default:
            return "Unknown";
    }
}

int getDirectionIndex(char *src)
{
    char *word = strtolower(src);
    if(strncmp(word, "east", 4) == 0)
        return 0;
    else if(strncmp(word, "north", 5) == 0)
        return 1;
    else if(strncmp(word, "west", 4) == 0)
        return 2;
    else if(strncmp(word, "south", 5) == 0)
        return 3;
    else
        return -1;
}

char *strtolower(char *str)
{
    int i;
    for(i = 0; str[i]; ++i)
        str[i] = tolower(str[i]);

    return str;
}

void cleanUpCmds(void)
{
    free(commands);
}

