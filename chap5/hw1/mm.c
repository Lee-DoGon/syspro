#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int fd;

	// file open
	fd = open(argv[1], O_RDWR);

	if ((fd) == -1)
	{
		perror("error");
		exit(1);
	}
	else
		printf("File read success\n");

	printf("Total Line : 4\n");
	printf("You can choose 1 ~ 4 Line\n");
	printf("Pls 'Enter' the line to select : ");

	char in;
	scanf("%c", &in);


	// file read
	char buf[1000];

	// read(fild, read file content, buf size)
	int	readB = read(fd, buf, sizeof(buf) - 1);
	
	if (readB == -1)
	{
		perror("error");
		close(fd);
		exit(1);
	}
	
	// '0' read until end of file
	buf[readB] = '\0';

	if (in == '*')
		printf("%s", buf);
	else
		exit(0);


	close(fd);
	exit(0); // return (0);
}
