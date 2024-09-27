#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE][MAXLINE];
char longest[MAXLINE];

int main(void)
{
	// int len, max = 0;

	for (int i = 0; i < 5; i++)
	{
		fgets(line[i], MAXLINE, stdin);

		// scanf("%s", line[i]);
		// len = strlen(line[i]);

		/*
		if (len > max)
		{
			max = len;
			copy(line[i], longest);
		}
		*/
	}

	
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (strcmp(line[i],line[j]) > 0)
			{
				strcpy(longest, line[i]);
				strcpy(line[i], line[j]);
				strcpy(line[j], longest);
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%s", line[i]);
	}

	return 0;
}
