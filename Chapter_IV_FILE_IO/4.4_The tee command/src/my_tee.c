#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

#define MAX_READ 20

int main(int argc, char *argv[])
{
    int fd, opt;
    char buf[MAX_READ + 1];
    ssize_t numRead;
    off_t offset;

    if (argc < 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s [-a] file");

    fd = open(argv[argc - 1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (fd == -1)
        errExit("open");

    offset = lseek(fd, 0, SEEK_SET);
    while ((opt = getopt(argc, argv, ":a")) != -1)
    {
        switch (opt)
        {
        case 'a':
            //file = optarg;
            offset = lseek(fd, -1, SEEK_END);
            if(offset == -1)
                errExit("lseek");
            break;
        case '?':
        default:
            fprintf(stderr, "%s option: '-%c' is invalid: ignore\n", argv[0], optopt);
            exit(EXIT_FAILURE);
            break;
        }
    }

    while ((numRead = read(STDIN_FILENO, buf, MAX_READ)) > 0)
    {
        buf[numRead] = '\0';

        if (write(STDOUT_FILENO, buf, numRead + 1) != (numRead + 1))
            fatal("couldn't write whole buf");
        if (write(fd, buf, numRead) != (numRead))
            fatal("couldn't write whole buf");
    }

    if (numRead == -1)
        errExit("read");

    if (close(fd) == -1)
        errExit("close file");

    exit(EXIT_SUCCESS);
}
