#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Command.h"
#include "Item.h"
void createRooms(void);
void setRoomMonster(void);
void createMonsters(void);
void createItems(void);
void createPlayer(void);
void play(void);
void printWelcome(void);
int processCommand(command *command);
void printHelp(void);
void goRoom(command *command);
int quit(command *command);
void pickupItem(int answer, item *item);
#endif
