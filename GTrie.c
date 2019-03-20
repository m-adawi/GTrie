#include<stdio.h>
#include<stdlib.h>
#include"GTrie.h"

unsigned int n = 0;

void load(GTrie *head, char *s)
{
    GTrie *pointer = head;
    for(int i = 0 ; s[i] ; i++)
    {
        bool found = false;
        for(GTrie *ptr = pointer->children ; ptr != NULL ; ptr = ptr->next)
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
            GTrie *tmp = calloc(1, sizeof(GTrie));
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



bool contains(GTrie *head, char *s)
{
    GTrie *pointer = head;
    for(int i = 0 ; s[i] ; i++)
    {
        bool found = false;
        for(GTrie *ptr = pointer->children ; ptr != NULL ; ptr = ptr->next)
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


void unload(GTrie *head)
{
    for(GTrie *ptr = head->children ; ptr != NULL ; /* unused */)
    {
        GTrie *tmp = ptr->next;
        unload(ptr);
        ptr = tmp;
    }

    free(head);
}

unsigned int size()
{
	return n;
}

