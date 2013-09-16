#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
typedef struct item {
    char *name;
    char *type;
    char *rareness;
    long damage;
}item;

char *getItemDesc(void);
#endif
