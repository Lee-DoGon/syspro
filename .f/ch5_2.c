#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024 // Size of the buffer

// Custom getchar function using read system call
int my_getchar() {
    static char buffer[BUFFER_SIZE]; // Buffer to hold read characters
    static int bytesRead = 0;         // Number of bytes read from the buffer
    static int bufferIndex = 0;       // Current index in the buffer

    // If the buffer is empty, read more data
    if (bufferIndex >= bytesRead) {
        bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE); // Read from standard input
        bufferIndex = 0; // Reset index for the new buffer
        if (bytesRead <= 0) {
            return EOF; // Return EOF on error or end of input
        }
    }

    // Return the next character from the buffer
    return (unsigned char)buffer[bufferIndex++];
}

int main() {
    int c;

    // Read characters using the custom getchar function
    while ((c = my_getchar()) != EOF) {
        putchar(c); // Output the character
    }

    return 0;
}
