#include "include/Dictionary.h"
#include <stdlib.h>
#include <string.h>

static struct nlist *hashtab[HASHSIZE];  /*pointer table */

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, listItem *_item)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdupl(name)) == NULL)
            return NULL;

        hashval = hash(name);
        np->next = hashtab[hashval];
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

    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);

    return p;
}
