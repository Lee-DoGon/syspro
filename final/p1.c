#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
/*
static void exit_handler1(void), exit_handler2(void);

int main(void)
{
	if (atexit(exit_handler1) != 0)
		perror("exit_handler1 can't regist");
	if (atexit(exit_handler2) != 0)
		perror("exit_handler1 can't regist");

	printf("main end\n");

	exit(0);
}

static void exit_handler1(void)
{
	printf("first exit handler1\n");
}

static void exit_handler2(void)
{
	printf("second exit handler2\n");
}
*/
int main()
{
	int pid1, pid2, child, status;

	pid1 = fork();

	if (pid1 == 0)
	{
		printf("Process [1] Execution\n");
		sleep(1);
		printf("Process [1] Execution\n");
		sleep(1);
	//	printf("^CInterrupt to child\n");
	//	printf("child killed\n");
		printf("parent killed\n");
		exit(2);
	}

	pid2 = fork();
	
	if (pid2 == 0)
	{
		printf("Process [1] Execution\n");
		sleep(1);
		printf("Process [1] Execution\n");
		printf("^CInterrupt to child\n");
		printf("child killed\n");
		exit(1);
	}

	child = waitpid(pid1, &status, 0);

}
