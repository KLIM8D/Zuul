#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED
#include "Room.h"
typedef struct command {
    char *firstWord;
    char *secondWord;
}command;

int processCommand(command *cmd, room **roomp);
void printHelp(void);
void printRoomExists(room *roomp);
void quit(void);
struct command *getCommand(char *line, command *cmd);
int getLine(char *s, int limit);
void goRoom(room **roomp, char* secondWord);
char *getDirection(int i);
int getDirectionIndex(char *word);
char *strtolower(char *str);
void initCommands(void);
void cleanUpCmds(void);
#endif
