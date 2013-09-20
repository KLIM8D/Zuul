#include "include/Game.h"
#include "include/Item.h"
#include "include/Dictionary.h"
#include "include/Player.h"
#include "include/Command.h"
#include <stdlib.h>
#include <stdio.h>

#define NITEMS 1

static struct player *playerp;

int main()
{
    init();
    initCommands();
    struct nlist *i;
    char *p;
    createItems();
    i = lookup("Crazy axe");
    if (i != NULL)
        printf("%s\n", (p = getItemDesc(i->_obj->_item)));
    else
        printf("Not found\n");

    free(p);

    play();

    return 0;
}

void createItems(void)
{
    int i;
    listItem *itemp;
    for(i = 0; i < NITEMS; ++i) {
       itemp = malloc(sizeof(*itemp));

       itemp->_item = createItem(i);

       install(itemp->_item->name, itemp, 0);
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
    playerp = createPlayer(name);
    printf("Let's get started, %s!\n", playerp->name); 
}

void play(void)
{
    printWelcome();
    struct room *currentRoom;
    currentRoom = createRooms();
    struct command *cmdp;
    cmdp = calloc(2, sizeof(command));
    char *line = calloc(50, sizeof(char));
    
    getCommand(line, cmdp);
    while(processCommand(cmdp, &currentRoom)) {
        getCommand(line, cmdp);
    }

    cleanup();
    if(cmdp->firstWord == NULL)
        free(line);

    free(cmdp->firstWord);
    free(cmdp->secondWord);
    free(cmdp);

    free(playerp->name);
    free(playerp->inventory);
    free(playerp);

    cleanUpCmds();
}
