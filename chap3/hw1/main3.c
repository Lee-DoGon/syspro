#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE][MAXLINE];
char longest[MAXLINE];

int main(void)
{
	int len, max = 0;

	for (int i = 0; i < 5; i++)
	{
		fgets(line[i], MAXLINE, stdin);
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (strcmp(line[i], line[j]) > 0)
			{
				copy(longest, line[i]);
				copy(line[i], line[j]);
				copy(line[j], longest);
			}
		}
	}


	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", line[i]);
	}

	return 0;
}
