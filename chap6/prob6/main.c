#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (link(argv[1], argv[2]) == -1)
    exit(1);

  exit(0);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3) { // 수정: 인자 수 확인
        fprintf(stderr, "Usage: %s <source> <link>\n", argv[0]);
        exit(1);
    }

    if (link(argv[1], argv[2]) == -1) {
        perror("link"); // 수정: 오류 메시지 출력
        exit(1);
    }

    exit(0);
}
*/
