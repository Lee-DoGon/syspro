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

		fp = fopen(argv[1], "r");

		if (fp == NULL)
			return 1;

		printFile(fp, lineNum);

		fclose(fp);
	}
}
