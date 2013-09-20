#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED
#include "Monster.h"
typedef struct room {
    char *name;
    char *description;
    struct monster *monster;
    /* 0: East; 1: North; 2: West; 3: South */
    struct room **nextRoom;
}room;

#define NROOMS 8
room *createRooms(void);
#endif
