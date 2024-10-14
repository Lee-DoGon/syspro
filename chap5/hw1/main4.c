#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	//if (argv != 2)
		//fprintf(stderr, "how to use : %s\n", argv[0]);

	// file open
	int fd = open(argv[1], O_RDWR);

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

	int	readB = read(fd, buf, sizeof(buf) - 1);
	
	if (readB == -1)
	{
		perror("error");
		close(fd);
		exit(1);
	}
	
	// '0' read until end of file
	buf[readB] = '\0';


//=========================================


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


//=========================================


	if (in == '*')
	{
		for (int i = 0; sent_count; i++)
		{
			printf("%s\n", sent[i]);
			free(sent[i]);
		}
	}
	else if (in == '1')
		printf("%s\n", sent[0]);
	else if (in == '2')
		printf("%s\n", sent[1]);
	else if (in == '3')
		printf("%s\n", sent[2]);
	else if (in == '4')
		printf("%s\n", sent[3]);
	else
		exit(0);


	close(fd);
	exit(0); // return (0);
}
