#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#ifndef BUF_SIZE /* Allow "cc -D" to override definition */
#define BUF_SIZE 1024
#endif
int main(int argc, char *argv[])
{
    int fd;
    /* Open existing file for reading */
    fd = open("startup", O_RDONLY);
    if (fd == -1)
        errExit("open");
    /* Open new or existing file for reading and writing, truncating to zero 
bytes; file permissions read+write for owner, nothing for all others */
    fd = open("myfile", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
        errExit("open");
    /* Open new or existing file for writing; writes should always
 append to end of file */
    fd = open("w.log", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,
              S_IRUSR | S_IWUSR);
    if (fd == -1)
        errExit("open");
}
