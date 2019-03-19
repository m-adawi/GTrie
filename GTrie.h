#ifndef Trie_H
#define Trie_H

#include<stdbool.h>

typedef struct Trie
{
    char c;
    bool is_word;
    struct Trie *next, *children;
}Trie;


void load(Trie *head, char *s);

bool contains(Trie *head, char *s);

void unload(Trie *head);

unsigned int size();

#endif
