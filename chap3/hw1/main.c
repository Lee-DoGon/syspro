#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[5][MAXLINE];
char longest[MAXLINE];

int main(void)
{
	int len, max = 0;

	int i = 0;


	while (i < 5)
	{
		fgets(line[i], MAXLINE, stdin);

		/*
		if (strlen(line[i]) > strlen(line[i+1]))
		{
			strcpy(longest, line[i+1]);
			strcpy(line[i+1], line[i]);
			strcpy(line[i], longest);
		}
		*/

		/*
		len = strlen(line);

		if (len > max)
		{
			max = len;
			copy(line, longest[i]);
		}
		*/

		i++;
	}


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; i < 5; j++)
		{
		
			if (strlen(line[i]) > strlen(line[i+1]))
			{
				strcpy(longest, line[i+1]);
				strcpy(line[i+1], line[i]);
				strcpy(line[i], longest);
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%s", line[i]);
	}

	return 0;
}
