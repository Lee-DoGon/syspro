#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // move end of file
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);

    // buf size
    char *buffer = (char *)malloc(fileSize + 1);
    if (!buffer) {
        perror("Memory allocation error");
        fclose(file);
        return 1;
    }

    // read file, save in buf
    fseek(file, 0, SEEK_SET);
    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0'; // 널 종료

    // file clode
    fclose(file);

    // Print the content in reverse order
    for (long i = fileSize - 1; i >= 0; i--) {
        if (buffer[i] == '\n' || i == 0) {
            // find start loc
            long start = (i == 0) ? 0 : i + 1;
            printf("%s", &buffer[start]); // print line
            // move end of line
            while (i > 0 && buffer[i - 1] != '\n') {
                i--;
            }
        }
    }

    free(buffer);
    return 0;
}
