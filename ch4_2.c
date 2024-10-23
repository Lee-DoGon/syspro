#include <stdio.h>
#include <string.h>

// Compare two files and print the first differing line

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s File1 File2\n", argv[0]);
        return 1;
    }

    FILE *fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        return 2;
    }

    FILE *fp2 = fopen(argv[2], "r");
    if (fp2 == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[2]);
        fclose(fp1);
        return 3;
    }

    char line1[256], line2[256];
    int lineNumber = 1; // Start counting lines from 1

    // Read lines from both files and compare
    while (fgets(line1, sizeof(line1), fp1) != NULL &&
           fgets(line2, sizeof(line2), fp2) != NULL) {
        // Compare the lines
        if (strcmp(line1, line2) != 0) {
            printf("First differing line at line %d:\n", lineNumber);
            printf("File1: %s", line1);
            printf("File2: %s", line2);
            break;
        }
        lineNumber++;
    }

    // Check if one file has more lines
    if (fgets(line1, sizeof(line1), fp1) != NULL) {
        printf("File1 has extra content starting from line %d:\n", lineNumber);
        printf("File1: %s", line1);
    } else if (fgets(line2, sizeof(line2), fp2) != NULL) {
        printf("File2 has extra content starting from line %d:\n", lineNumber);
        printf("File2: %s", line2);
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);

    return 0;
}
