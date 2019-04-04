#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define FILE_PATH "/home/trap.py"

int main() {
    int fd;

    // Create pipe
    if (mkfifo(FILE_PATH, 0666) == -1) {
        // Allow program to continue if pipe already exists
        if (errno != EEXIST) {
            perror("Error while creating pipe");
            return 1;
        }
    }

    // Open file to write data
    fd = open(FILE_PATH, O_WRONLY | O_CREAT, (mode_t) 0600);
    if (fd == -1) {
        perror("Error while opening file for writing!");
        return 2;
    }
    for (int i = 0 ; i < 100000 ; i++)
        if (write(fd, "0", strlen("0")) < 0) {
            close(fd);
            perror("Error writing data to file!\n");
            return 4;
        }

    close(fd);

    system("sudo bash countermeasure.sh");

    return 0;
}