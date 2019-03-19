# GTrie
A Trie data structure for C/C++ language used to store C strings and to check if a specififc string exists in it or not, it aims to be effecient in speed and memory usage, so, unlike the popular Trie it uses linked lists in its nodes instead of arrays of pointers which requires a lot of memory, it doesn't matter if the string is alphabetical or not, ASCII or unicode.

The complexity of inserting a new string with the function "void load(GTrie *head, char* word)" is in the worst case O(256*n), where n is the number of characters in the string, the same complexity when checking wethter a string exists or not with the function "bool contains(GTrie *head, char *word)".


The file called "speller.zip" contains a C project that is an example of a beneficial usage of this data structure, which is a program that prompts the user to enter the path to a dictionary file, the path to the file to be spelled, and optionally a file to put the result in instead of outputting it to the terminal, and there is a folder named "samples" that contains an English dictionary and two files to be spelled.

This project "speller" is inspired from Pset5 in the great free course CS50 https://www.edx.org/course/cs50s-introduction-to-computer-science 


I've also made a C++ version of this data structure as a Class in a file called GTriecpp.h.
