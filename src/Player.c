#include "include/Player.h"
#include "include/Dictionary.h"
#include <stdlib.h>

long calcExp(player *playerp, long gain)
{
    if(playerp->maxExperience == (playerp->experience+gain)) {
        playerp->level++;
        playerp->experience += gain;
        playerp->maxExperience *= 2;
    }
    else
        playerp->experience += gain;

    return playerp->experience;
}

/* takeDmg: return > 1 if player is still alive; else < 1 */
long takeDmg(player *playerp, monster *monsterp)
{
    long dmgDealt = *(monsterp->damage)*(1-(playerp->armor/100));
    playerp->healthPoints -= dmgDealt;
    if(playerp->healthPoints <= 0)
        return -1;
    
    return 1;
}

player *createPlayer(char *name)
{
    player *pp = malloc(sizeof(player));

    pp->name = strdupl(name);
    pp->experience = 0;
    pp->maxExperience = 100;
    pp->healthPoints = 100;
    pp->level = 1;
    pp->weapon = lookup("Crazy axe")->_obj->_item;
    pp->inventory = calloc(INVENTORY_SPACE, sizeof(item *));

    return pp;
}
