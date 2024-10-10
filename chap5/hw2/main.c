#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int fd;

	// read file
	if ((fd = open(argv[1], O_RDWR)) == -1)
	{
		perror(argv[1]);
		exit(1);
	}




	/*
	FILE *fpr, *fpw;

	if (argc != 3)
	{
		fprintf(stderr, "error : %s\n", argv[0]);
		return 1;
	}

	if ((fpr = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "file open error");
		return 2;
	}*/

	/*
	if ((fpw = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "file open error");
		return 2;
	}
	*/

	/*
	fseek(fpr, 0L, SEEK_END);

	long l = ftell(fpr);
	char c;

	for (long i = 1L; i <= l; i++)
	{
		fseek(fpr, -i, SEEK_END);
		c = fgetc(fpw);
		fputc(c, fpw);
	}

	fputc('\n', fpw);

	fclose(fpr);
	fclose(fpw);*/
}
