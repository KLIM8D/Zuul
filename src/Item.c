#include "include/Item.h"
#include <stdio.h>

/*static struct item _item;*/
static struct item _item;
struct item *itemp = &_item;

char *getItemDesc(void)
{
    char description[1000];
    char *p = description;
        sprintf(description, "Name: %s\nType: %s\nRare: %s\nDamage: %ld", itemp->name, itemp->type, itemp->rareness, itemp->damage);

    return p;
}

