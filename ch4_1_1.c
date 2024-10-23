#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;
    int lineNumber = 1; // To keep track of the line number
    int numbered = 0;   // Flag for -n option

    // Check command line arguments for -n option
    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numbered = 1; // Set flag if -n option is present
        if (argc < 3) {
            fp = stdin; // If no file is provided, read from stdin
        } else {
            fp = fopen(argv[2], "r"); // Open the specified file
        }
    } else if (argc >= 2) {
        fp = fopen(argv[1], "r"); // Open the specified file
    } else {
        fp = stdin; // If no file is provided, read from stdin
    }

    // Check if the file opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read characters from the file or stdin
    c = getc(fp);
    if (numbered) {
        printf("%d\t", lineNumber); // Print line number for the first line
    }

    while (c != EOF) {
        // Print the character
        putc(c, stdout);
        
        // Check for newline character to handle line numbering
        if (c == '\n') {
            if (numbered) {
                lineNumber++; // Increment line number
                printf("%d\t", lineNumber); // Print the next line number
            }
        }
        
        // Read the next character
        c = getc(fp);
    }

    // Close the file if it was opened
    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}
