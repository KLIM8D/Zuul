#include "include/Item.h"
#include <stdio.h>
#include <stdlib.h>

/*static struct item _item;*/

char *getItemDesc(item *itemp)
{
    char description[1000];
    char *p = description;
    sprintf(description, "Name: %s\nType: %s\nRare: %s\nDamage: %ld", itemp->name, itemp->type, itemp->rareness, itemp->damage);

    return p;
}

item *createItem(int i)
{
    item *itemp;
    itemp = (item *) malloc (sizeof(item));
    switch(i) {
        case 0:
            itemp->name = "Crazy axe";
            itemp->type = "Axe";
            itemp->rareness = "Uncommon";
            itemp->damage = 7;
            break;
        case 1:
            itemp->name = "Awesome spear";
            itemp->type = "Spear";
            itemp->rareness = "Rare";
            itemp->damage = 12;
            break;
        case 2:
            itemp->name = "Abandoned Greatsword";
            itemp->type = "Sword";
            itemp->rareness = "Uncommon";
            itemp->damage = 10;
            break;
        case 3:
            itemp->name = "Chipped Timber Axe";
            itemp->type = "Axe";
            itemp->rareness = "Common";
            itemp->damage = 4;
            break;
        case 4:
            itemp->name = "Shattered Bow";
            itemp->type = "Bow";
            itemp->rareness = "Rare";
            itemp->damage = 12;
            break;
        case 5:
            itemp->name = "Dulled Shiv";
            itemp->type = "Knife";
            itemp->rareness = "Epic";
            itemp->damage = 20;
            break;
        case 6:
            itemp->name = "Stormhammer Head";
            itemp->type = "Hammer";
            itemp->rareness = "Epic";
            itemp->damage = 25;
            break;
        case 7:
            itemp->name = "Flamewashed Mace";
            itemp->type = "Mace";
            itemp->rareness = "Uncommon";
            itemp->damage = 12;
            break;
        case 8:
            itemp->name = "Ice Cleaver";
            itemp->type = "Axe";
            itemp->rareness = "Uncommon";
            itemp->damage = 14;
            break;
        default:
            itemp->name = "Great Axe";
            itemp->type = "Axe";
            itemp->rareness = "Uncommon";
            itemp->damage = 6;
            break;
    }

    return itemp;
}
