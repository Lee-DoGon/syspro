#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE]; // input line
char longest[MAXLINE]; // longest line

int main(void)
{
	int len, max = 0;

	
	while (fgets(line, MAXLINE, stdin) != NULL)
	{
		len = strlen(line);

		if (len > max)
		{
			max = len;
			copy(line, longest);
		}

		i++;
	}


	for (int i = 0; i < 5; i++)
	{
		printf("%s", longest);
	}

	return 0;

}
