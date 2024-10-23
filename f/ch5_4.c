#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256 // Buffer size for reading lines

// Function to compare two files
void compare_files(int fd1, int fd2) {
    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    int lineNumber = 1;

    ssize_t bytesRead1, bytesRead2;

    while ((bytesRead1 = read(fd1, buffer1, sizeof(buffer1) - 1)) > 0 &&
           (bytesRead2 = read(fd2, buffer2, sizeof(buffer2) - 1)) > 0) {
        
        buffer1[bytesRead1] = '\0'; // Null terminate for comparison
        buffer2[bytesRead2] = '\0'; // Null terminate for comparison

        // Compare the read buffers
        if (strcmp(buffer1, buffer2) != 0) {
            // Print the differing lines
            printf("First differing line at line %d:\n", lineNumber);
            printf("File1: %s", buffer1);
            printf("File2: %s", buffer2);
            break;
        }

        // Increment line count
        lineNumber++;
    }

    // Check if one file has more lines
    if (bytesRead1 > 0) {
        printf("File1 has extra content starting from line %d:\n", lineNumber);
        write(STDOUT_FILENO, buffer1, bytesRead1); // Output remaining data
    } else if (bytesRead2 > 0) {
        printf("File2 has extra content starting from line %d:\n", lineNumber);
        write(STDOUT_FILENO, buffer2, bytesRead2); // Output remaining data
    }
}

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        write(STDERR_FILENO, "Usage: <program> File1 File2\n", 30);
        return 1;
    }

    // Open the first file
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening file");
        return 2;
    }

    // Open the second file
    int fd2 = open(argv[2], O_RDONLY);
    if (fd2 == -1) {
        perror("Error opening file");
        close(fd1);
        return 3;
    }

    // Compare the two files
    compare_files(fd1, fd2);

    // Close the file descriptors
    close(fd1);
    close(fd2);

    return 0;
}
