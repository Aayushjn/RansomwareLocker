#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_PATH "/trap_pipe.py"

int main() {
    int fd;
    char *buf = NULL;

    fd = open(FILE_PATH, O_RDONLY | O_CREAT, (mode_t) 0600);
    ssize_t res = read(fd, buf, 1);

    close(fd);

    return 0;
}