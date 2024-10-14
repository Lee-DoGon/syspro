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

	
//------------------------------------------------
	// save sent []
	char **sent = malloc(1000 * sizeof(char));
	int sent_count = 0;

	// div sent
	char *token = strtok(buf, "\n");

	while (token != NULL)
	{
		sent[sent_count] = malloc(strlen(token) + 1);
		strcpy(sent[sent_count], token);
		sent_count++;
		token = strtok(NULL, "\n");
	}

	// print sent
	for (int i = 0; sent_count; i++)
	{
		printf("%s\n", sent[i]);
		free(sent[i]);
	}

	free(sent);
//------------------------------------------------


	close(fd);
	exit(0); // return (0);
}
