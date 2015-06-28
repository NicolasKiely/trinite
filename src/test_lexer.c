/**
 * Tests for lexical data structures
 */
#include "test.h"
#include "lexer.h"

int test_default_no_parent_lexical();

int main(int argc, char *argv[]){
    test(test_default_no_parent_lexical,
        "Could not initialize default lexical structure");
    RETURN_TEST_SUCCEEDED;
}



/*****************************************************************************\
 * Test cases
\*****************************************************************************/

/* Test creation of lexical structure with default settings */
int test_default_no_parent_lexical(){
    struct Lexical *pLex;
    int ret = -1;

    pLex = new_Lexical(-1, NULL);
    ret = ret && (pLex != NULL);
    ret = ret && (pLex->pBuf != NULL);
    ret = ret && (pLex->bufSize == LEXICAL_BUFFER_SIZE);
    ret = ret && (pLex->strLen == 0);
    ret = ret && (pLex->pNext == NULL);

    free_Lexical(&pLex);

    return !ret;
}
