#ifndef GTrie_H
#define GTrie_H

#include<stdbool.h>

typedef struct GTrie
{
    char c;
    bool is_word;
    struct GTrie *next, *children;
}GTrie;


void load(GTrie *head, char *s);

bool contains(GTrie *head, char *s);

void unload(GTrie *head);

unsigned int size();

#endif
