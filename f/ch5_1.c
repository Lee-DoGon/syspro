#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024 // Buffer size for reading

int main(int argc, char *argv[]) {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // If no file is provided, read from standard input
    if (argc < 2) {
        // Read from standard input (file descriptor 0)
        while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytesRead); // Write to standard output
        }
        if (bytesRead == -1) {
            perror("Error reading from standard input");
            exit(1);
        }
    } else {
        // Loop through each file provided in command line arguments
        for (int i = 1; i < argc; i++) {
            fd = open(argv[i], O_RDONLY); // Open file for reading
            if (fd == -1) {
                perror("Error opening file");
                exit(1);
            }

            // Read from the file and write to standard output
            while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
                write(STDOUT_FILENO, buffer, bytesRead);
            }
            if (bytesRead == -1) {
                perror("Error reading from file");
                close(fd);
                exit(1);
            }

            close(fd); // Close the file descriptor
        }
    }

    return 0;
}
