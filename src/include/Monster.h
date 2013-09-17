#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include "Item.h"
#define INVENTORY_SPACE 10
typedef struct monster {
    int id;
    char *name;
    struct item items[INVENTORY_SPACE];
    long damage;
    long health;
}monster;

long attack(void);
long getHealth(void);
long hit(long damage);
#endif
