#include <stdio.h>

// 2 file in

int main(int argc, char *argv[])
{
    char c;
    FILE *fp1, *fp2;

    if (argc != 3)
        return 1;

    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL)
    {
        fprintf(stderr, "File %s Open Error\n", argv[1]);
        return 2;
    }

	// "a" - append _ file add
    fp2 = fopen(argv[2], "a");
    if (fp2 == NULL)
    {
        fprintf(stderr, "File %s Open Error\n", argv[2]);
        fclose(fp1);
        return 3;
    }

    while ((c = fgetc(fp1)) != EOF)
    {
        fputc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
