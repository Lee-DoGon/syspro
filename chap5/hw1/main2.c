#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 5
#define MAX_LINE_LEN 100

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "how to use : %s \n", argv[0]);

	// file open
	int fd =  open(argv[1], O_RDWR);

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


//	char *saveDivText[MAX_LINE];
	
//	for (int i = 0; i < MAX_LINE; i++)
//		saveDivText[i] = (char*)malloc(MAX_LINE_LEN);

//	printf("Total Line : %d\n", MAX_LINE);
//	printf("You can choose 1 ~ %d Line\n", MAX_LINE);
//	printf("Pls 'Enter' the line to select : ");


	printf("\nTotal Line : 4\n");
	printf("You can choose 1 ~ 4 Line\n");
	printf("Pls 'Enter' the line to select : ");

	char input;
	scanf("%c", &input);
//	int num;
//	scanf("%d", &num);
//	scanf("%c", &input);
//	printf("\n");

	/*
	if (num < 1 || num > MAX_LINE)
	{
		fprintf(stderr, "enter onther num betw 1 ~ %d\n", MAX_LINE);
		close(fd);
		exit(1);
	}
	*/

	char buf[MAX_LINE_LEN];
	int lineCount = 0;

	int readFD = read(fd, buf, sizeof(buf) - 1);
//	char saveDivText[5][50];



	// file read
//	char buf2[1000];

	// read(fild, read file content, buf size)
//	int	readB = read(fd, buf, sizeof(buf) - 1);

	
	// '0' read until end of file
	buf[readFD] = '\0';

	// print text

	if (input == '*')
		printf("%s", buf);

//---------------------------------




//---------------------------------
/*

	while (lineCount < MAX_LINE && readFD > 0)
	{
		char *ptr = strtok(buf, "\n");

		while (ptr != NULL && lineCount < MAX_LINE)
		{
			strncpy(saveDivText[lineCount], ptr, MAX_LINE_LEN - 1);
			saveDivText[lineCount][MAX_LINE_LEN - 1] = '\0';

			lineCount++;

			ptr = strtok(NULL, "\n");
		}
	}


	// print select line
	printf("%s\n", saveDivText[num - 1]);



	for (int i = 0; i < MAX_LINE; i++)
		free(saveDivText[i]);

*/
//---------------------------------


//---------------------------------
/*
	while (readB > 0)
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
*/
//---------------------------------


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
}
