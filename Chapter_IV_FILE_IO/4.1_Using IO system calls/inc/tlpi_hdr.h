#ifndef TLPI_HDR_H
#define TLPI_HDR_H /* Prevent accidental double inclusion */

#include <sys/types.h>       /* Type definitions used by many programs */
#include <stdio.h>           /* Standard I/O functions */
#include <stdlib.h>          /* Prototypes of commonly used library functions,plus EXIT_SUCCESS and EXIT_FAILURE constants */
#include <unistd.h>          /* Prototypes for many system calls */
#include <errno.h>           /* Declares errno and defines error constants */
#include <string.h>          /* Commonly used string-handling functions */
#include "get_num.h"         /* Declares our functions for handling numericarguments (getInt(), getLong()) */
#include "error_functions.h" /* Declares our error-handling functions */

typedef enum
{
    FALSE,
    TRUE
} Boolean;

#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) > (n) ? (m) : (n))

void errMsg(const char *format, ...);
void errExit(const char *format, ...);
void err_exit(const char *format, ...);
void errExitEN(int errnum, const char *format, ...);

int getInt(const char *arg, int flags, const char *name);
long getLong(const char *arg, int flags, const char *name);

#endif
