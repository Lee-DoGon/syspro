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

	// find first line
	char *end_of_line = NULL;

	for (int i = 0; i < readB; i++)
	{
		if (buf[i] == '\n')
		{
			end_of_line = &buf[i];
			break;
		}
	}

	// find secound line
	char *end_of_sec_line = NULL;

	if (*end_of_first_line)
	{
		
		for (int i = end_of_line - buf + 1; i < readB; i++)
		{
			if (buf[i] == '\n')
			{
				end_of_sec_line = &buf[i];
				break;
			}
		}
	}

	// print first line
	if (end_of_line)
	{
		int len = end_of_line - buf + 1;
		char first_line[len + 1];

		strncpy(first_line, buf, len);
		printf("%s", first_line);
	}

	close(fd);
	exit(0); // return (0);
}
