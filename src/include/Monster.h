#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include "Item.h"
#define MONSTER_ITEMS 10
typedef struct monster {
    int *id;
    char *name;
    struct item *items[MONSTER_ITEMS];
    long *damage;
    long *health;
}monster;

long attack(void);
long getHealth(void);
long hit(long damage);
#endif
