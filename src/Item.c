#include "include/Item.h"
#include <stdio.h>

static struct item *_item;
char *getItemDesc(void)
{
    char description[1000];
    char *p = description;
    if(_item != NULL)
    {
        sprintf(description, "Name: %s\nType: %s\nRare: %s\nDamage: %ld", _item->name, _item->type,_item->rareness,_item->damage);
    }

    return p;
}
