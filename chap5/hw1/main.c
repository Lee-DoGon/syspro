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


/*
	// count Line
	FILE *fp;
	int line = 0;
	char c;

	fp = fopen("test.txt", "r");

	while (fscanf(fp, "%c", &c) != EOF)
		if (c == '\n')
			line++;

	fclose(fp);
	
	printf("Total Line : %d \nYou can choose 1 ~ %d Line\n", line, line);
*/


	printf("Total Line : 4\n");
	printf("You can choose 1 ~ 4 Line\n");
	printf("Pls 'Enter' the line to select : ");

	int num;
	scanf("%d", &num);
	printf("\n");



	char buf[100];
	int readB = read(fd, &buf, 100);
	char saveDivText[5][50];

	int i = 0, j =5;

	while (read(fd, buf, sizeof(buf)) > 0)
	{
		char *ptr = strtok(buf, "\n");

		while (ptr != NULL && i < j)
		{
			strncpy(saveDivText[i++], ptr, j);
			ptr = strtok(NULL, "\n");
		}
	}

	for (int i = 0; i < num; i++)
		printf("%s\n", saveDivText[num]);



//---------------------------------
/*
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

	// print text
	//	printf("%s", buf);
*/
//---------------------------------


//---------------------------------
/*
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

*/
//---------------------------------


	close(fd);
	exit(0); // return (0);
}
