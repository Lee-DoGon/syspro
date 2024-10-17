#include <stdio.h>

int main(int argc, char *argv[])
{
	char c;
	FILE *fp1, *fp2;

	if (argc != 3)
		return 1;

	fp1 = fopen(argv[1], "w");


	if (fp1 == NULL)
		return 2;

	fp2 = fopen(argv[2], "r");


	while ((c = fgetc(fp1)) != EOF)
		fputc(c , fp2);


	fclose(fp1);
	fclose(fp1);

	return 0;
}
