#ifndef DICT_H_INCLUDED
#define DICT_H_INCLUDED
#include "Item.h"
#include "Monster.h"
#include "Room.h"

#define HASHSIZE 101

typedef union {
    struct item *_item;
    struct room *_room;
    struct monster *_monster;
} listItem;

/* table entry */
struct nlist { 
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    int type;
    listItem *_obj;
}nlist;

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, listItem *_item, int type);
struct nlist *undef(char *name);
char *strdupl(char *);
void init(void);
void cleanup(void);
#endif
