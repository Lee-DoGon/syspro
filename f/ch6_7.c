#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <utime.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat buf;
    struct utimbuf time;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s source_file target_file\n", argv[0]);
        exit(1);
    }

    // Get information about the source file
    if (stat(argv[1], &buf) < 0) {
        perror("stat()");
        exit(-1);
    }

    // Prepare time structure with access and modification times
    time.actime = buf.st_atime;
    time.modtime = buf.st_mtime;

    // Try to set the times for the target file
    if (utime(argv[2], &time) < 0) {
        // If utime fails, try to create the file
        int fd = open(argv[2], O_CREAT | O_RDWR, 0644);
        if (fd < 0) {
            perror("open()");
            exit(-1);
        }
        
        // Set the access and modification times for the newly created file
        if (utime(argv[2], &time) < 0) {
            perror("utime");
            close(fd);
            exit(-1);
        }

        close(fd);
    }

    exit(0);
}
