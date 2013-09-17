#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED
#include "Monster.h"
typedef struct room {
    char *name;
    char *description;
    struct monster *monster;
    struct room *nextRoom;
}room;

#endif
