#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_PATH "temp_file"

int main() {
    printf("Main\n");
    int fd;
    char *buf = NULL;

    printf("Here\n");
    fd = open(FILE_PATH, O_RDONLY | O_CREAT, (mode_t) 0600);
    ssize_t res = read(fd, buf, 1);

    printf("%zi\n", res);

    close(fd);

    return 0;
}