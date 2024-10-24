#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "store.h"

int main(int argc, char *argv[])
{
	int fd, id;
	char c;
	struct store rec;

	if (argc < 2)
		exit(1);

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror(argv[1]);

		exit(2);
	}



	int num;

	printf("list of all goods, 1: list of available goods ) ");
	
	scanf("%d", &num);

	if (num == 0)
	{
		// file read
		char buf[1000];
	
		int	readB = read(fd, buf, sizeof(buf) - 1);
		
		if (readB == -1)
			exit(1);
		
		// '0' read until end of file
		buf[readB] = '\0';

		printf("%s\n", buf);
	}
	else {}

	close(fd);

	exit(0);
}
