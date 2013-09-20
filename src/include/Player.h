#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Item.h"
#include "Monster.h"
#define INVENTORY_SPACE 250
typedef struct player {
    char *name;
    long experience;
    long maxExperience;
    long healthPoints;
    long level;
    item *weapon;
    long armor;
    item **inventory;
}player;

long calcExp(player *playerp,long gain);
long takeDmg(player *playerp, monster *monsterp);
long attack(void);
player *createPlayer(char *name);
#endif
