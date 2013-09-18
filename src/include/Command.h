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
struct command *getCommand(command *cmd);
int getLine(char *s, int limit);
void goRoom(room **roomp);
#endif
