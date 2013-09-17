#include "include/Game.h"
#include "include/Item.h"
#include "include/Dictionary.h"
#include <stdlib.h>
#include <stdio.h>

#define NITEMS 1

int main()
{
    struct nlist *i;
    createItems();
    i = lookup("Crazy axe");
    if (i != NULL)
        printf("%s\n", getItemDesc(i->_obj->_item));
    else
        printf("Not found\n");

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
