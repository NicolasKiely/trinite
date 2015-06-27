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
    int strlen;

    struct Lexical *pNext;
};


/**
 * Create new lexical buffer
 * - initSize: Initial buffer size, set negative for program default
 * - pParent: Optional parent element to append new struct to
 * Returns newly created struct
 * Side effects: Changes parent's child pointer, if parent is given
 */
struct Lexical *new_Lexical(int initSize, struct Lexical *pParent);

/**
 * Recursively free buffer
 * - ppBuf: Double pointer to struct to free
 * Returns void
 * Side effects: Frees buffer
 */
void free_Lexical(struct Lexical **ppBuf);

#endif
