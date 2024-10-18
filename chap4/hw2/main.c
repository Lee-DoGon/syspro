#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFile(FILE *fp, int lineNumP, const char *fileName) {
    int c;
    int lineNum = 1;

    if (lineNumP)
        printf("%d: ", lineNum);

    while ((c = getc(fp)) != EOF) {
        putc(c, stdout);

        if (c == '\n') {
            lineNum++;

            if (lineNumP) {
                printf("%d: ", lineNum);
            }
        }
    }
}


int main(int argc, char *argv[]) {
    FILE *fp;
    int lineNumP = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            lineNumP = 1;
        } else {
            fp = fopen(argv[i], "r");
            if (fp == NULL) {
                fprintf(stderr, "Error opening file %s\n", argv[i]);
                return 1;
            }

            printFile(fp, lineNumP, argv[i]);

            fclose(fp);
        }
    }

    if (argc == 1) {
        printf("Enter text (Ctrl+D to end):\n");
        fp = stdin;
        printFile(fp, lineNumP, "stdin");
    }

    return 0;
}
