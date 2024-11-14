#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int pid1, pid2, child, status;
	printf("[%d] start parent process\n", getpid());

	pid1 = fork();

	if (pid1 == 0)
	{
		printf("[%d] start child process [1]\n", getpid());
		sleep(1);
		printf("[%d] end child process [1]\n", getpid());
		exit(1);
	}

	pid2 = fork();
	
	if (pid2 == 0)
	{
		printf("[%d] start child process #2\n", getpid());
		sleep(2);
		printf("[%d] end child process #2\n", getpid());
		exit(2);
	}

	child = waitpid(pid1, &status, 0);
	printf("[%d] end %d child process #1\n", getpid(), child);
	printf("\tend code %d\n", status>>8);
}
