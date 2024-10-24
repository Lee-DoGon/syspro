#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// 1 file con

int main(int argc, char* argv[])
{
	int fd;

	if (argc == 2)
	{
		// file open
		fd = open(argv[1], O_RDWR);
	
		if ((fd) == -1)
		{
			perror("error");
			exit(1);
		}


		// file read
		char buf[1000];

		int	readB = read(fd, buf, sizeof(buf) - 1);
	
		if (readB == -1)
		{
			perror("error");
			close(fd);
			exit(1);
		}
	
		// '0' read until end of file
		buf[readB] = '\0';
	

		// save sent[]
		char **sent = malloc(100 * sizeof(char));
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
	
		for (int i = 0; i < 2; i++)
			printf("%s\n", sent[i]);
	}


//==============================================================
	

	char in[10];

	if (argc == 3)
	{

//		char in[10];
//		scanf("%s", in);

		*in = *argv[1];
		fd = open(argv[2], O_RDWR);

		// file read
		char buf[1000];

		int	readB = read(fd, buf, sizeof(buf) - 1);
	
		if (readB == -1)
		{
			perror("error");
			close(fd);
			exit(1);
		}
	
		// '0' read until end of file
		buf[readB] = '\0';
	

		// save sent[]
		char **sent = malloc(100 * sizeof(char));
		int sent_count = 0;
	
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

		for (int i = 0; i < count; i++)
		{
	//		if (par[i] == in)
				printf("%s\n", par[i]);
		}
	}

//	printf("%s", buf);

	exit(0);
}
