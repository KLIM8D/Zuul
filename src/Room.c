#include "include/Room.h"
#include "include/Dictionary.h"
#include <stdlib.h>

room *createRooms(void)
{
    struct room *a[NROOMS];
    struct room *r1 = calloc(4, sizeof(room));
    struct room *r2 = calloc(4, sizeof(room));
    struct room *r3 = calloc(4, sizeof(room));
    struct room *r4 = calloc(4, sizeof(room));
    struct room *r5 = calloc(4, sizeof(room));
    struct room *r6 = calloc(4, sizeof(room));
    struct room *r7 = calloc(4, sizeof(room));
    struct room *r8 = calloc(4, sizeof(room));

    r1->nextRoom = calloc(4, sizeof(room));
    r2->nextRoom = calloc(4, sizeof(room));
    r3->nextRoom = calloc(4, sizeof(room));
    r4->nextRoom = calloc(4, sizeof(room));
    r5->nextRoom = calloc(4, sizeof(room));
    r6->nextRoom = calloc(4, sizeof(room));
    r7->nextRoom = calloc(4, sizeof(room));
    r8->nextRoom = calloc(4, sizeof(room));

    r1->name = strdupl("Entrance");
    r1->description = strdupl("The entrance to the castle");

    r2->name = strdupl("Hallway");
    r2->description = strdupl("The hallway");

    r3->name = strdupl("Kitchen");
    r3->description = strdupl("The kitchen");

    r4->name = strdupl("Stairway");
    r4->description = strdupl("Starway to \"heaven\"");

    r5->name = strdupl("Dinning room");
    r5->description = strdupl("The dinning room");

    r6->name = strdupl("Basement");
    r6->description = strdupl("The basement");

    r7->name = strdupl("Dungeon");
    r7->description = strdupl("A dungeon with a lot of corpses");

    r8->name = strdupl("Ceiling"); 
    r8->description = strdupl("The ceiling");

    r1->nextRoom[0] = NULL;
    r1->nextRoom[1] = r2;
    
    r2->nextRoom[0] = r3;
    r2->nextRoom[1] = r4;
    r2->nextRoom[2] = r6;
    r2->nextRoom[3] = r1;

    r3->nextRoom[1] = r5;
    r3->nextRoom[2] = r2;

    r4->nextRoom[1] = r8;
    r4->nextRoom[3] = r2;

    r5->nextRoom[3] = r3;

    r6->nextRoom[0] = r2;
    r6->nextRoom[1] = r7;

    r7->nextRoom[3] = r6;

    r8->nextRoom[3] = r4;

    a[0] = r1;
    a[1] = r2;
    a[2] = r3;
    a[3] = r4;
    a[4] = r5;
    a[5] = r6;
    a[6] = r7;
    a[7] = r8;

    int i;
    listItem *itemp;
    for(i = 0; i < NROOMS; ++i) {
       itemp = malloc(sizeof(*itemp));

       itemp->_room = a[i];

       install(itemp->_room->name, itemp, 1);
    }

    return lookup("Entrance")->_obj->_room;
}
