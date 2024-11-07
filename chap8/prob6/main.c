#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

// uid_t getuid(); // pro real user id
// uid_t geteuid(); // pro user id
// uid_t getgid(); // pro real group id
// uid_t getegid(); // pro group id

int main()
{
	printf("my realistic user id : %d(%s)\n", getuid(), getpwuid(getuid())->pw_name);
	printf("my valid user id : %d(%s)\n", geteuid(), getpwuid(geteuid())->pw_name);
	printf("my realistic group id : %d(%s)\n", getgid(), getgrgid(getgid())->gr_name);
	printf("my valid group id : %d(%s)\n", getgid(), getgrgid(getuid())->gr_name);
}
