#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int pid;
	pid = fork();

	if (pid == 0)
		printf("[child] : hello, world pid = %d\n", getpid());
	else
		printf("[parent] : hello world pid = %d\n", getpid());
}
