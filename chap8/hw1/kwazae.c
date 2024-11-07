#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

// uid_t getuid(); // pro real user id
// uid_t geteuid(); // pro user id
// uid_t getgid(); // pro real group id
// uid_t getegid(); // pro group id

int main(int argc, char *argv[])
{
	int op_e = 0;
	int op_u = 0; // pro real user id
	int op_g = 0; // pro real group id
	int op_i = 0; // pro id
	int op_p = 0; // parent pro id

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-e") == 0)
			op_e = 1;
		else if (strcmp(argv[i], "-u") == 0)
			op_u = 1;

		else if (strcmp(argv[i], "-g") == 0)
			op_g = 1;

		else if (strcmp(argv[i], "-i") == 0)
			op_i = 1;

		else if (strcmp(argv[i], "-p") == 0)
			op_p = 1;
	}

	////////////////////
	if (op_e == 1)
	{
		char **ptr;
		extern char **environ;

		for (ptr = environ; *ptr != 0; ptr++)
			printf("%s\n", *ptr);

		exit(0);
	}
	else if (op_u == 1)
	{
		printf("my realistic user id : %d(%s)\n", getuid(), getpwuid(getuid())->pw_name);
		printf("my valid user id : %d(%s)\n", geteuid(), getpwuid(geteuid())->pw_name);
	}
	else if (op_g == 1)
	{
	printf("my realistic group id : %d(%s)\n", getgid(), getgrgid(getgid())->gr_name);
	printf("my valid group id : %d(%s)\n", getgid(), getgrgid(getuid())->gr_name);
	}
	else if (op_i == 1)
	{
		printf("my process number : [%d]\n", getpid());

		exit(0);
	}
	else if (op_p == 1)
	{
		printf("my parent's process number : [%d]\n", getppid());

		exit(0);
	}
}



















	/*
	printf("my realistic user id : %d(%s)\n", getuid(), getpwuid(getuid())->pw_name);
	printf("my valid user id : %d(%s)\n", geteuid(), getpwuid(geteuid())->pw_name);
	printf("my realistic group id : %d(%s)\n", getgid(), getgrgid(getgid())->gr_name);
	printf("my valid group id : %d(%s)\n", getgid(), getgrgid(getuid())->gr_name);
	*/
