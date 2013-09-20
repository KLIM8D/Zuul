#include "include/Item.h"
#include "include/Dictionary.h"
#include <stdio.h>
#include <stdlib.h>

/*static struct item _item;*/

char *getItemDesc(item *itemp)
{
    char *description = malloc(1000);
    sprintf(description, "Name: %s\nType: %s\nRare: %s\nDamage: %ld", itemp->name, itemp->type, itemp->rareness, *(itemp->damage));

    return description;
}

item *createItem(int i)
{
    item *itemp = malloc(sizeof(*itemp));
    long *dmgp = malloc(sizeof(long));
    switch(i) {
        case 0:
            itemp->name = strdupl("Crazy axe");
            itemp->type = strdupl("Axe");
            itemp->rareness = strdupl("Uncommon");
            *dmgp = 7;
            itemp->damage = dmgp;
            break;
        case 1:
            itemp->name = strdupl("Awesome spear");
            itemp->type = strdupl("Spear");
            itemp->rareness = strdupl("Rare");
            *dmgp = 12;
            itemp->damage = dmgp;  
            break;
        case 2:
            itemp->name = strdupl("Abandoned Greatsword");
            itemp->type = strdupl("Sword");
            itemp->rareness = strdupl("Uncommon");
            *dmgp = 10;
            itemp->damage = dmgp;
            break;
        case 3:
            itemp->name = strdupl("Chipped Timber Axe");
            itemp->type = strdupl("Axe");
            itemp->rareness = strdupl("Common");
            *dmgp = 4;
            itemp->damage = dmgp;
            break;
        case 4:
            itemp->name = strdupl("Shattered Bow");
            itemp->type = strdupl("Bow");
            itemp->rareness = strdupl("Rare");
            *dmgp = 12;
            itemp->damage = dmgp;
            break;
        case 5:
            itemp->name = strdupl("Dulled Shiv");
            itemp->type = strdupl("Knife");
            itemp->rareness = strdupl("Epic");
            *dmgp = 20;
            itemp->damage = dmgp;
            break;
        case 6:
            itemp->name = strdupl("Stormhammer Head");
            itemp->type = strdupl("Hammer");
            itemp->rareness = strdupl("Epic");
            *dmgp = 25;
            itemp->damage = dmgp;
            break;
        case 7:
            itemp->name = strdupl("Flamewashed Mace");
            itemp->type = strdupl("Mace");
            itemp->rareness = strdupl("Uncommon");
            *dmgp = 12;
            itemp->damage = dmgp;
            break;
        case 8:
            itemp->name = strdupl("Ice Cleaver");
            itemp->type = strdupl("Axe");
            itemp->rareness = strdupl("Uncommon");
            *dmgp = 14;
            itemp->damage = dmgp;
            break;
        default:
            itemp->name = strdupl("Great Axe");
            itemp->type = strdupl("Axe");
            itemp->rareness = strdupl("Uncommon");
            *dmgp = 6;
            itemp->damage = dmgp;
            break;
    }

    return itemp;
}
