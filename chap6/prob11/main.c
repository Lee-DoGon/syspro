#include <dirent.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char *, char *, struct stat *, int, int, int);

int main(int argc, char *argv[])
{
  DIR *dp;
  char *dir = ".";
  struct dirent *d;
  struct stat st;
  char path[BUFSIZ + 1];

  int op_i = 0;
  int op_p = 0;
  int op_q = 0;


  for (int i = 1; i < argc; i++)
  {
	  if (strcmp(argv[i], "-i") == 0)
		  op_i = 1;
	  else if (strcmp(argv[i], "-p") == 0)
		  op_p = 1;
	  else if (strcmp(argv[i], "-Q") == 0)
		  op_q = 1;
	  else
		  dir = argv[i];
  }

//  if (argc == 2)
//   dir = ".";
//  else
//	  dir = ".";
//    dir = argv[1];

  if ((dp = opendir(dir)) == NULL) // dir open
    perror(dir);

  while ((d = readdir(dp)) != NULL)
  {
    sprintf(path, "%s/%s", dir, d->d_name);

    if (lstat(path, &st) < 0)
      perror(path);
    else
      printStat(path, d->d_name, &st, op_i, op_p, op_q);
  }

  closedir(dp);

  exit(0);
}


void printStat(char *pathname, char *file, struct stat *st, int op_i, int op_p, int op_q)
{
	if (op_i)
		printf("%ld ", st->st_ino);

	printf("%c%s ", type(st->st_mode), perm(st->st_mode));

	if (op_p && S_ISDIR(st->st_mode))
		printf("%s/ ", file);
	else 
	{
		if (op_q)
			printf("\"%s\" ", file);
		else
			printf("%s ", file);
	}

	printf("\n");
}


char type(mode_t mode)
{
  if (S_ISREG(mode))
    return ('-');
  if (S_ISDIR(mode))
    return ('d');
  if (S_ISCHR(mode))
    return ('c');
  if (S_ISBLK(mode))
    return ('b');
  if (S_ISLNK(mode))
    return ('l');
  if (S_ISFIFO(mode))
    return ('p');
  if (S_ISSOCK(mode))
    return ('s');
}


char *perm(mode_t mode)
{
  static char perms[10];
  strcpy(perms, "--------");

  for (int i = 0; i < 3; i++)
  {
    if (mode & (S_IRUSR >> i * 3))
      perms[i * 3] = 'r';

    if (mode & (S_IWUSR >> i * 3))
      perms[i * 3] = 'w';

    if (mode & (S_IXUSR >> i * 3))
      perms[i * 3] = 'x';
  }

  return (perms);
}
