#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char* argv[])
{
	struct student rec;
	FILE *fp;

	if (argc != 2)
		return 1;

	if ((fp = fopen(argv[1], "rb")) == NULL)
		return 2;

	printf("==========================\n");
	printf("%12s %8s %8s\n", "StudentID", "Name", "Score");
	printf("==========================\n");

	while (fread(&rec, sizeof(rec), 1, fp) > 0)
		if (rec.id != 0)
			printf("%10d %6s %6d\n", rec.id, rec.name, rec.score);

	printf("==========================\n");

	fclose(fp);

	return 0;
}
