#include <stdlib.h>
#include <string.h>
#include "lexer.h"


struct Lexical *new_Lexical(int initSize, struct Lexical *pParent){
    struct Lexical *pLex;

    /* Malloc structure */
    pLex = malloc(sizeof(struct Lexical));
    if (pLex == NULL){ return NULL; }

    /* Initialize internal variables */
    pLex->strLen = 0;
    pLex->pNext = 0;

    pLex->bufSize = (initSize < 0) ? LEXICAL_BUFFER_SIZE : initSize;
    if (pLex->bufSize > 0){
        /* Initialize new string buffer */
        pLex->pBuf = calloc(pLex->bufSize, sizeof(char));
        if (pLex->pBuf == NULL){
            /* Failed to allocate memory */
            pLex->bufSize = 0;
            free(pLex);
            return NULL;
        }

    } else {
        /* No new string buffer */
        pLex->pBuf = NULL;
    }

    /* Add new struct to parent if given */
    if (pParent != NULL){
        /* Drop old child struct */
        free_Lexical(&pParent->pNext);
        pParent->pNext = pLex;
    }

    return pLex;
}


void free_Lexical(struct Lexical **ppLex){
    struct Lexical *pLex;
    if (ppLex == NULL){ return; }
    pLex = *ppLex;
    if (pLex == NULL){ return; }
    
    /* Clean children first */
    if (pLex->pNext != NULL){
        free_Lexical(&pLex->pNext);
    }

    /* Clean internal fields */
    if (pLex->pBuf != NULL){
        if (pLex->bufSize > 0){
            /* Only clear if bufsize set */
            free(pLex->pBuf);
        }
        pLex->pBuf = NULL;
    }
    pLex->bufSize = 0;
    pLex->strLen = 0;

    /* Clean self */
    free(pLex);

    /* Zero out pointer */
    *ppLex = NULL;
}


struct Lexical *weakParseString_Lexical(char *str, int n){
    struct Lexical *pLex=NULL;
    int i=0;
    char c;

    /* Loop over n characters, if n is positive */
    for (i=0; n<=0 || i<n; i++){
        c = str[i];

        /* Check for null terminator, if fixed length not given */
        if (n<=0 && c=='\0'){ break; }

        /* Lexical logic */
        /* TODO */
    }

    return pLex;
}
