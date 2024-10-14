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

	char in[10];
	scanf("%s", in);


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


	// *
	if (in[0] == '*')
	{
		for (int i = 0; sent_count; i++)
		{
			printf("%s\n", sent[i]);
			free(sent[i]);
		}
	}


	// 1
	else if (in[0] == '1')
	{
		if (in[1] == '-')
		{
			if (in[2] == '1')
				printf("%s\n", sent[0]);
			else if (in[2] == '2')
			{
				printf("%s\n", sent[0]);
				printf("%s\n", sent[1]);
			}
			else if (in[2] == '3')
			{
				printf("%s\n", sent[0]);
				printf("%s\n", sent[1]);
				printf("%s\n", sent[2]);
			}
			else if (in[2] == '4')
			{
				printf("%s\n", sent[0]);
				printf("%s\n", sent[1]);
				printf("%s\n", sent[2]);
				printf("%s\n", sent[3]);
			}
		}
		else if (in[1] == ',')
		{
			if (in[2] == '1')
				printf("%s\n", sent[0]);
			else if (in[2] == '2')
			{
				printf("%s\n", sent[0]);
				printf("%s\n", sent[1]);
			}
			else if (in[2] == '3')
			{
				printf("%s\n", sent[0]);
				printf("%s\n", sent[2]);
			}
			else if (in[2] == '4')
			{
				printf("%s\n", sent[0]);
				printf("%s\n", sent[3]);
			}
		}
		else
			printf("%s\n", sent[0]);
	}


	// 2
	else if (in[0] == '2')
	{
		if (in[1] == '-')
		{
			if (in[2] == '2')
				printf("%s\n", sent[1]);
			else if (in[2] == '3')
			{
				printf("%s\n", sent[1]);
				printf("%s\n", sent[2]);
			}
			else if (in[2] == '4')
			{
				printf("%s\n", sent[1]);
				printf("%s\n", sent[2]);
				printf("%s\n", sent[3]);
			}
		}
		else if (in[1] == ',')
		{
			if (in[2] == '2')
			{
				printf("%s\n", sent[1]);
			}
			else if (in[2] == '3')
			{
				printf("%s\n", sent[1]);
				printf("%s\n", sent[2]);
			}
			else if (in[2] == '4')
			{
				printf("%s\n", sent[2]);
				printf("%s\n", sent[3]);
			}
		}
		else
			printf("%s\n", sent[1]);
	}


	// 3
	else if (in[0] == '3')
	{
		if (in[1] == '-')
		{
			if (in[2] == '3')
				printf("%s\n", sent[2]);
			else if (in[2] == '4')
			{
				printf("%s\n", sent[2]);
				printf("%s\n", sent[3]);
			}
		}
		else if (in[1] == ',')
		{
			if (in[2] == '3')
			{
				printf("%s\n", sent[2]);
			}
			else if (in[2] == '4')
			{
				printf("%s\n", sent[2]);
				printf("%s\n", sent[3]);
			}
		}
		else
			printf("%s\n", sent[2]);
	}


	// 4
	else if (in[0] == '4')
	{
		if (in[1] == '-')
		{
			if (in[2] == '4')
				printf("%s\n", sent[3]);
		}
		else if (in[1] == ',')
		{
			if (in[2] == '4')
			{
				printf("%s\n", sent[3]);
			}
		}
		else
			printf("%s\n", sent[3]);
	}


//	else if (in[0] == '2')
//		printf("%s\n", sent[1]);
	

//	else if (in[0] == '3')
//		printf("%s\n", sent[2]);
	

//	else if (in[0] == '4')
//		printf("%s\n", sent[3]);
	

	else
		exit(0);


	close(fd);
	exit(0); // return (0);
}
