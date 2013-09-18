#include "include/Room.h"
#include "include/Dictionary.h"
#include <stdlib.h>

#define NROOMS 3

room *createRooms(void)
{
    struct room *a[NROOMS];
    struct room *r1 = (room *) malloc(sizeof(room));
    struct room *r2 = (room *) malloc(sizeof(room)); 
    struct room *r3 = (room *) malloc(sizeof(room));  

    r1->name = "Entrance";
    r1->description = "The entrance to the castle";

    r2->name = "Hallway";
    r2->description = "The hallway";

    r3->name = "Kitchen";
    r3->description = "The kitchen";
    
    r1->nextRoom = r2;
    r2->nextRoom = r3;

    a[0] = r1;
    a[1] = r2;
    a[2] = r3;

    int i;
    listItem *itemp;
    for(i = 0; i < NROOMS; ++i) {
       itemp = (listItem *) malloc (sizeof(listItem));

       itemp->_room = a[i];

       install(itemp->_room->name, itemp);
    }

    return lookup("Entrance")->_obj->_room;
}
