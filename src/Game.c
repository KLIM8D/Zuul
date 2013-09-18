#include "include/Game.h"
#include "include/Item.h"
#include "include/Dictionary.h"
#include "include/Player.h"
#include "include/Command.h"
#include <stdlib.h>
#include <stdio.h>

#define NITEMS 1

static struct player *playerp;
static struct room *currentRoom;

int main()
{
    struct nlist *i;
    createItems();
    i = lookup("Crazy axe");
    if (i != NULL)
        printf("%s\n", getItemDesc(i->_obj->_item));
    else
        printf("Not found\n");

    play();

    return 0;
}

void createItems(void)
{
    int i;
    listItem *itemp;
    for(i = 0; i < NITEMS; ++i) {
       itemp = (listItem *) malloc (sizeof(listItem));

       itemp->_item = createItem(i);

       install(itemp->_item->name, itemp);
    }
}

void printWelcome(void)
{

    char name[50];
    printf("Welcome to the World of Zuul!\n");
    printf("World of Zuul is a new, incredibly boring adventure game.\n\n");
    printf("Type 'help' if you need help.\n\n");
    printf("Write your name: ");
    scanf("%49s", name);
    getchar();
    createPlayer(name);
}

void createPlayer(char *name)
{
    playerp = (player *) malloc (sizeof(player));
    playerp->name = name;
    playerp->experience = 0;
    playerp->maxExperience = 100;
    playerp->healthPoints = 100;
    playerp->level = 1;
    playerp->weapon = lookup("Crazy axe")->_obj->_item;

    printf("Let's get started, %s!\n", playerp->name); 
}

void play(void)
{
    printWelcome();
    currentRoom = createRooms();
    int running = 0;
    struct command *cmdp;
    cmdp = (command *) malloc(sizeof(command));

    getCommand(cmdp);
    while((running = processCommand(cmdp, &currentRoom))) {
        getCommand(cmdp);
    }

    printf("lolll\n");
}
