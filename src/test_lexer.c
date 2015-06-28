/**
 * Tests for lexical data structures
 */
#include "test.h"
#include "lexer.h"

/* Simple structure creations */
int create_default_no_parent_lexical();
int create_empty_no_parent_lexical();
int create_fixed_no_parent_lexical();
int create_default_with_parent_lexical();
int create_empty_with_parent_lexical();
int create_fixed_with_parent_lexical();


int main(int argc, char *argv[]){
    test(create_default_no_parent_lexical,
        "Could not initialize default lexical structure");
    test(create_empty_no_parent_lexical,
        "Could not initialize empty lexical structure");
    test(create_fixed_no_parent_lexical,
        "Could not initialize fixed-size lexical structure");
    test(create_default_with_parent_lexical,
        "Could not initialize default child lexical structure");
    test(create_empty_with_parent_lexical,
        "Could not initialize empty child lexical structure");
    test(create_fixed_with_parent_lexical,
        "Could not initialize fixed-size child lexical structure");

    RETURN_TEST_SUCCEEDED;
}



/*****************************************************************************\
 * Test cases
\*****************************************************************************/

/* Test creation of lexical structure with default settings */
int create_default_no_parent_lexical(){
    struct Lexical *pLex;
    int ret = -1;

    pLex = new_Lexical(-1, NULL);
        ret = ret && (pLex != NULL);
        ret = ret && (pLex->pBuf != NULL);
        ret = ret && (pLex->bufSize == LEXICAL_BUFFER_SIZE);
        ret = ret && (pLex->strLen == 0);
        ret = ret && (pLex->pNext == NULL);
    free_Lexical(&pLex);
        ret = ret && (pLex == NULL);

    return !ret;
}


/* Test creation of empty lexical structure */
int create_empty_no_parent_lexical(){
    struct Lexical *pLex;
    int ret = -1;

    pLex = new_Lexical(0, NULL);
        ret = ret && (pLex != NULL);
        ret = ret && (pLex->pBuf == NULL);
        ret = ret && (pLex->bufSize == 0);
        ret = ret && (pLex->strLen == 0);
        ret = ret && (pLex->pNext == NULL);
    free_Lexical(&pLex);
        ret = ret && (pLex == NULL);

    return !ret;
}


/* Test creation of lexical structure with default settings */
int create_fixed_no_parent_lexical(){
    struct Lexical *pLex;
    int ret = -1;

    pLex = new_Lexical(27, NULL);
        ret = ret && (pLex != NULL);
        ret = ret && (pLex->pBuf != NULL);
        ret = ret && (pLex->bufSize == 27);
        ret = ret && (pLex->strLen == 0);
        ret = ret && (pLex->pNext == NULL);
    free_Lexical(&pLex);
        ret = ret && (pLex == NULL);

    return !ret;
}


/* Test creation of default child lexicals */
int create_default_with_parent_lexical(){
    struct Lexical *pLex, *pChild;
    int ret = -1;

    pLex = new_Lexical(-1, NULL);
        ret = ret && (pLex != NULL);
        ret = ret && (pLex->pBuf != NULL);
        ret = ret && (pLex->bufSize == LEXICAL_BUFFER_SIZE);
        ret = ret && (pLex->strLen == 0);
        ret = ret && (pLex->pNext == NULL);
    pChild = new_Lexical(-1, pLex);
        ret = ret && (pChild != NULL);
        ret = ret && (pLex->pNext == pChild);
        ret = ret && (pChild->pBuf != NULL);
        ret = ret && (pChild->bufSize == LEXICAL_BUFFER_SIZE);
        ret = ret && (pChild->strLen == 0);
        ret = ret && (pChild->pNext == NULL);
    free_Lexical(&pLex);
        ret = ret && (pLex == NULL);

    return !ret;
}


/* Test creation of empty child lexicals */
int create_empty_with_parent_lexical(){
    struct Lexical *pLex, *pChild;
    int ret = -1;

    pLex = new_Lexical(-1, NULL);
        ret = ret && (pLex != NULL);
        ret = ret && (pLex->pBuf != NULL);
        ret = ret && (pLex->bufSize == LEXICAL_BUFFER_SIZE);
        ret = ret && (pLex->strLen == 0);
        ret = ret && (pLex->pNext == NULL);
    pChild = new_Lexical(0, pLex);
        ret = ret && (pChild != NULL);
        ret = ret && (pLex->pNext == pChild);
        ret = ret && (pChild->pBuf == NULL);
        ret = ret && (pChild->bufSize == 0);
        ret = ret && (pChild->strLen == 0);
        ret = ret && (pChild->pNext == NULL);
    free_Lexical(&pLex);
        ret = ret && (pLex == NULL);

    return !ret;
}


/* Test creation of fixed-size lexicals */
int create_fixed_with_parent_lexical(){
    struct Lexical *pLex, *pChild;
    int ret = -1;

    pLex = new_Lexical(-1, NULL);
        ret = ret && (pLex != NULL);
        ret = ret && (pLex->pBuf != NULL);
        ret = ret && (pLex->bufSize == LEXICAL_BUFFER_SIZE);
        ret = ret && (pLex->strLen == 0);
        ret = ret && (pLex->pNext == NULL);
    pChild = new_Lexical(53, pLex);
        ret = ret && (pChild != NULL);
        ret = ret && (pLex->pNext == pChild);
        ret = ret && (pChild->pBuf != NULL);
        ret = ret && (pChild->bufSize == 53);
        ret = ret && (pChild->strLen == 0);
        ret = ret && (pChild->pNext == NULL);
    free_Lexical(&pLex);
        ret = ret && (pLex == NULL);

    return !ret;
}
