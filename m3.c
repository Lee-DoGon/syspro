#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// div str

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

  // print nomal str
//	printf("%s", buf);


//---------------------------------

	// div line

	// save div line
	char *par[100];
	int count = 0;

	// strtok, div line \n\n
	char *token = strtok(buf, "\n");

	while (token != NULL && count < 100)
	{
		// save line
		par[count++] = token;
		token = strtok(NULL, "\n");
	}

	//print line
	for (int i = count - 1; i >= 0; i--)
	{
		printf("%s\n", par[i]);
	}

//---------------------------------


	close(fd);
	exit(0); // return (0);
}
