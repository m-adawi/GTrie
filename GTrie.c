#include<stdio.h>
#include<stdlib.h>
#include"GTrie.h"

unsigned int n = 0;

void load(Trie *head, char *s)
{
    Trie *pointer = head;
    for(int i = 0 ; s[i] ; i++)
    {
        bool found = false;
        for(Trie *ptr = pointer->children ; ptr != NULL ; ptr = ptr->next)
        {
            if(ptr->c == s[i])
            {
                found = true;
                pointer = ptr;
                break;
            }
        }

        if(!found)
        {
            Trie *tmp = calloc(1, sizeof(Trie));
            tmp->c = s[i];

            if(pointer->children == NULL)
                pointer->children = tmp;
            else
            {
                tmp->next = pointer->children;
                pointer->children = tmp;
            }

            pointer = tmp;
        }
    }

    pointer->is_word = true;
    n++;
}



bool contains(Trie *head, char *s)
{
    Trie *pointer = head;
    for(int i = 0 ; s[i] ; i++)
    {
        bool found = false;
        for(Trie *ptr = pointer->children ; ptr != NULL ; ptr = ptr->next)
        {
            if(ptr->c == s[i])
            {
                found = true;
                pointer = ptr;
                break;
            }
        }

        if(!found)
        {
            return false;
        }
    }

    return pointer->is_word;
}


void unload(Trie *head)
{
    for(Trie *ptr = head->children ; ptr != NULL ; /* unused */)
    {
        Trie *tmp = ptr->next;
        unload(ptr);
        ptr = tmp;
    }

    free(head);
}

unsigned int size()
{
	return n;
}

