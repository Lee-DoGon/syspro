#include <stdio.h>
#include <stdlib.h>

#define MAX 80

int main(int argc, char *argv[])
{
	FILE *fp;
	int line = 0;
	char buf[MAX];

	if (argc != 2)
	{
		fprintf(stderr, "how to use : line FileName\n");

		exit(1);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error Open File\n");

		exit(2);
	}


	while (fgets(buf, MAX, fp) != NULL)
	{
		line++;

		printf("%3d %s", line, buf);
	}

	exit(0);
}
