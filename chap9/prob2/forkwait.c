#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int pid, child, status;
	printf("[%d] start parent process\n", getpid());

	pid = fork();

	if (pid == 0)
	{
		printf("[%d] start child process\n", getpid());
		exit(1);
	}

	child = wait(&status);
	printf("[%d] end %d child process\n", getpid(), child);
	printf("\tend code %d\n", status>>8);
}
