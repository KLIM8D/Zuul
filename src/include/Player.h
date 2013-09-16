#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Item.h";
#define INVENTORY_SPACE 250
typedef struct player {
    char *name;
    long experience;
    long maxExperience;
    long healthPoints;
    long level;
    Item weapon;
    Item inventory[INVENTORY_SPACE];
}player;

void calcExp(long gain);
long getHealth(void);
long hit(long damage);
long attack(void);
#endif
