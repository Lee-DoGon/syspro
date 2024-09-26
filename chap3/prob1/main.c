#include <stdio.h>
#include <string.h>
#include "copy.h"

// syspro

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
	}

	if (max > 0)
		printf("%s", longest);

	return 0;

}
