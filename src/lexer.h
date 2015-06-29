/**
 * Breaks query strings into lexical elements
 */
#ifndef LEXER_H
#define LEXER_H

#define LEXICAL_BUFFER_SIZE 16


/* Linked list of lexical buffers */
struct Lexical {
    char *pBuf;
    int bufSize;
    int strLen;

    struct Lexical *pNext;
};


/**
 * Create new lexical buffer
 * - initSize: Initial buffer size, set negative for program default
 * - pParent: Optional parent element to append new struct to
 * Returns newly created struct
 * Side effects: Changes parent's child pointer, if parent is given
 * Memory: Allocates returned struct on heap, caller responsible
 */
struct Lexical *new_Lexical(int initSize, struct Lexical *pParent);


/**
 * Recursively free buffer
 * - ppBuf: Double pointer to struct to free
 * Returns void
 * Side effects: Frees buffer
 * Memory: Frees struct and all child nodes. Other pointers
 *   to child nodes will be dangling.
 */
void free_Lexical(struct Lexical **ppBuf);


/**
 * Builds new lexical element list from c string
 * - str: C-style string to parse
 * - n: If positive read only first n bytes, otherwise read until \0
 * Returns parent node to ordered list of lexical structs
 * Side effects: Memory allocation
 * Memory: Allocates new list of struct nodes. Caller responsible.
 *   Struct nodes will point to string buffer. If string buffer
 *   is freed, internal pointers will be dangling.
 */
struct Lexical *weakParseString_Lexical(char *str, int n);


#endif
