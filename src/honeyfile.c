#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_PATH "/tmp/temp_file"
#define FILE_SIZE 4096

int main() {
    int fd;
    __off_t result;

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

    // Move file pointer to (FILE_SIZE - 1) location
    result = lseek(fd, FILE_SIZE - 1, SEEK_SET);
    if (result == -1) {
        close(fd);
        perror("Error calling lseek() to 'stretch' the file!");
        return 3;
    }

    // Write EOF as last byte
    result = write(fd, "\0", 1);
    if (result < 0) {
        close(fd);
        perror("Error writing data to file!");
        return 4;
    }

    close(fd);

    // TODO: Counter-measure

    return 0;
}