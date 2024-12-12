#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#define MAXLINE 100

int main()
{
	int n, pid, pid2, fd[2], fd2[2];
	char line[MAXLINE];

	pipe(fd);
	pipe(fd2);

	if ((pid = fork()) == 0)
	{
		dup2(fd[0], 1); // p3
		//close(fd[1]);
		close(fd[0]);

		dup2(fd[1], 1); // p1
		//close(fd[1]);

		dup2(fd[0], 1); // p2
		//close(fd[0]);

		printf("Hello\n");
		printf("Hello\n");
	}
	else
	{
		close(fd[1]);
		while ((n = read(fd[0], line, MAXLINE))>0)
			write(STDOUT_FILENO, line, n);
	}


/*
	if ((pid2 = fork()) == 0)
	{
		dup2(fd2[0], 1);
		//close(fd2[1]);
		close(fd2[0]);
		printf("Hello\n");
	}
	else
	{
		close(fd2[1]);
		while ((n = read(fd2[0], line, MAXLINE))>0)
			write(STDOUT_FILENO, line, n);
	}
*/
	printf("Hello\n");
	return 0;
}
