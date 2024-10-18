#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFile(FILE *fp, int lineNumP, const char *fileName) {
    int c;
    int lineNum = 1;

    if (lineNumP) {
        printf("=== %s ===\n", fileName);
        printf("%d: ", lineNum);
    }

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
            lineNumP = 1; // 줄 번호 출력 활성화
        } else {
            // 파일 열기
            fp = fopen(argv[i], "r");
            if (fp == NULL) {
                fprintf(stderr, "Error opening file %s\n", argv[i]);
                return 1;
            }

            printFile(fp, lineNumP, argv[i]);

            fclose(fp);
        }
    }

    // 인자가 없는 경우 표준 입력 처리
    if (argc == 1) {
        printf("Enter text (Ctrl+D to end):\n");
        fp = stdin;
        printFile(fp, lineNumP, "stdin");
    }

    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFile(FILE *fp, int lineNumP)
{
	int c;
	int lineNum = 1;

	if (lineNumP)
		printf("%d: ", lineNum);

	while ((c = getc(fp)) != EOF)
	{
		putc(c, stdout);

		if (c == '\n')
		{
			lineNum++;

			if (lineNumP)
				printf("%d: ", lineNum);
		}
	}
}


int main(int argc, char *argv[])
{
	FILE *fp;
	int c;
	int lineNum = 0;


	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], '\n') == 0)
		{
			lineNum = 1;
		}
//		else
//		{
//			if (i > 1)
//			printf("\n=== %s ===\n", argv[i]);
//		}

		fp = fopen(argv[1], "r");

		if (fp == NULL)
			return 1;

		printFile(fp, lineNum);

		fclose(fp);
	}
}
*/
