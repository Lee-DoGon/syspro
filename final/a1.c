#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAXLINE 100

int main(int argc, char* argv[])
{
	int n, pid, fd[2], pid2, fd2[2];
	char line[MAXLINE];

	pipe(fd);

	if ((pid = fork()) == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);

		if ((pid2 = fork()) == 0)
		{
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);
		}
		else
		{
			close(fd[1]);
			printf("The result from child process2\n");
	
			while ((n = read(fd[0], line, MAXLINE))>0)
				write(STDOUT_FILENO, line, n);
		}

		printf("Hello! pipe\n");

	}
	else
	{
		close(fd[1]);
		printf("The result from child process\n");

		while ((n = read(fd[0], line, MAXLINE))>0)
			write(STDOUT_FILENO, line, n);
	}

	exit(0);
}
