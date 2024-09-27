#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE][MAXLINE];
char longest[MAXLINE];

int main(void)
{
	int len, max = 0;
	int i = 0;

	for (int i = 0; i < 5; i++)
	{
		fgets(line[i], MAXLINE, stdin);
		
		len = strlen(line);

		if (len > max)
		{
			max = len;
			copy(line, longest);
		}
	}

	char temp;
	int max2 = strlen(line[0]);

	for (int i = 0; i < 5; i++)
	{
		if (strlen(line[i]) > max)
		{
			temp = line[i];
			line[i] = line[0];
			line[0] = temp;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%s", line[i]);
	}

	return 0;
}
