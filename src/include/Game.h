#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Command.h"
#include "Item.h"
void setRoomMonster(void);
void createMonsters(void);
void createItems(void);
void play(void);
void printWelcome(void);
void pickupItem(int answer, item *item);
#endif
