#ifndef GTRIE_H
#define GTRIE_H

#include<stdlib.h>


class GTrie
{
    typedef struct Trie
    {
        char c;
        bool is_word;
        struct Trie *next, *children;
    }Trie;

    Trie *head;
    unsigned int n;
public:
    GTrie()
    {
        head = (Trie*)calloc(1, sizeof(Trie));
        n = 0;
    }



    void load(char *s)
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
                Trie *tmp = (Trie*)calloc(1, sizeof(Trie));
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



    bool contains(char *s)
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

    unsigned int size()
    {
        return n;
    }

    ~GTrie()
    {
        unload(head);
    }

private:

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

};

#endif // GTRIE_H
