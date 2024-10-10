#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE][MAXLINE];
char longest[MAXLINE];

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		fgets(line[i], MAXLINE, stdin);
	}
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			// strcmp, string comparison
			// if return val < 0 _ str1 < str2
			// if val == 0 _ str1 == str2
			// val > 0 _ str1 > str2
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
