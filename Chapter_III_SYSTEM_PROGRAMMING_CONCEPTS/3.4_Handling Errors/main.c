#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define pathname "/home/hualai/"

int main()
{
    int fd;
    int cnt;
    char buf[1024] = {0};
    fd = open(pathname, O_CREAT, "rw-r–r–"); /* system call to open a file */
    if (fd == -1)
    {
        perror("open");
        printf("fd open = -1\n");
    }
    //if (close(fd) == -1)
    //{
    //    printf("fd close = -1");
    //}
    cnt = read(fd, buf, 1024);
    if (cnt == -1)
    {
        if (errno == EINTR)
            fprintf(stderr, "read was interrupted by a signal\n");
        else
        {
            printf("fd read erro, errno = %d\n", errno);
        }
    }
    return 0;
}
