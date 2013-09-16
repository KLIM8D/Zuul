#include "include/Game.h"
#include "include/Item.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    extern item *itemp;

    itemp->name = "Best item";
    itemp->type = "Axe";
    itemp->rareness = "Epic";
    itemp->damage = 100;


    printf("%s\n", getItemDesc());

    return 0;
}
