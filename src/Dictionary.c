#include "include/Dictionary.h"
#include <stdlib.h>
#include <string.h>

static struct nlist **hashtab; /*pointer table */

void init(void)
{
    hashtab = calloc(HASHSIZE, sizeof(*hashtab));
    /*int i;
    for (i = 0; i < HASHSIZE; hashtab[i++] = NULL)
        ;*/
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, listItem *_item, int type)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = malloc(sizeof(*np));
        if (np == NULL || (np->name = strdupl(name)) == NULL)
            return NULL;

        hashval = hash(name);
        np->next = hashtab[hashval];
        np->type = type;
        np->_obj = _item;
        hashtab[hashval] = np;
    }
    else
        free((void *) np->_obj);

    /*if ((np->defn = strdupl(defn)) == NULL)
        return NULL;*/

    return np;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;

    return NULL;
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    
    return hashval % HASHSIZE;
}

/* undef: undefine a definition, and remove it from hashtab */
struct nlist *undef(char *name)
{
    struct nlist *np = lookup(name);
    if(np == NULL)
        return NULL;

    if(np->next != NULL)
        hashtab[hash(name)] = lookup(np->next->name);
    else
        hashtab[hash(name)] = NULL;

    return np;
}

/* strdup: make a duplicate of s */
char *strdupl(char *s)
{
    char *p;

    p = malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);

    return p;
}


void cleanup(void)
{
    int i;
    struct nlist *np;
    for (i = 0; i < HASHSIZE; ++i) {
        np = hashtab[i];
        if(np != NULL) {
            free(np->name);
            free(np->next);
            if(np->type == 0) {
                free(np->_obj->_item->name);
                free(np->_obj->_item->type);
                free(np->_obj->_item->rareness);
                free(np->_obj->_item->damage);
                free(np->_obj->_item);
            }
            else if(np->type == 1) {
                free(np->_obj->_room->name);
                free(np->_obj->_room->description);
                free(np->_obj->_room->monster);
                free(np->_obj->_room->nextRoom);
                free(np->_obj->_room);
            }
            else {
                free(np->_obj->_monster->id);
                free(np->_obj->_monster->name);
                free(np->_obj->_monster->items);
                free(np->_obj->_monster->damage);
                free(np->_obj->_monster->health);
                free(np->_obj->_monster);
            }

            free(np->_obj);
        }
        free(np);
    }

    free(hashtab);
}
