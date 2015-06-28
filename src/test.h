/**
 * Self-contained testing functions
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>


/* Short-cut for finishing a successful test program */
#define RETURN_TEST_SUCCEEDED return registerSuccess(argv[0])
#define PASS_EXTENSION ".pass"


/**
 * Runs a function test. If test function returns failure,
 * it prints the error message and exits
 * - func: Function to call. Return nonzero for test failure
 * - msg: Error message to display in case of failure
 * Returns void
 * Side effects: Exits program on error
 */
void test(int (*func)(), const char *msg){
    if (func() != 0){
        printf("Test failure: %s\n", msg);
        exit(EXIT_FAILURE);
    }
}


/**
 * Registers a full test execution as successful.
 * Call as "return register_success(argv[0]);" in test's main()
 * Or use TEST_SUCCEEDED macro
 * - arg0: First argument to argv, the program name
 * Returns EXIT_SUCCESS
 * Side effects: Creates new file <program name>.pass
 *   Also writes current time to file
 */
int registerSuccess(char *arg0){
    char *newname;
    int namelen, extlen, ret;
    FILE *fpass;
    time_t timenow;
    char strnow[20];

    /* Calculate file name sizes */
    namelen = strlen(arg0);
    extlen = strlen(PASS_EXTENSION);

    /* Create new file name */
    newname = malloc(namelen + extlen + 1);
    if (newname == NULL){
        perror("register_success");
        return EXIT_FAILURE;
    }
    memcpy(newname, arg0, namelen);
    memcpy(newname+namelen, PASS_EXTENSION, extlen);
    newname[namelen+extlen] = '\0';

    /* Open file */
    fpass = fopen(newname, "w");
    free(newname);
    if (fpass == NULL){
        perror("register_success");
        return EXIT_FAILURE;
    }

    /* Get current time and write to file */
    timenow = time(NULL);
    strftime(strnow, 20, "%Y-%m-%d %H:%M:%S", localtime(&timenow));
    fwrite(strnow, sizeof(char), 19, fpass);

    /* Close file */
    ret = fclose(fpass);
    assert(ret == 0);
    
    return EXIT_SUCCESS;
}
