#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void calculate_directory_size(const char *dir_path, long *total_size) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dir = opendir(dir_path);

    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    // Read each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        // Get information about the entry
        if (stat(full_path, &statbuf) == -1) {
            perror("stat error");
            continue;
        }

        // If it's a regular file, add its size
        if (S_ISREG(statbuf.st_mode)) {
            *total_size += statbuf.st_size;
        }
        // If it's a directory, recurse into it
        else if (S_ISDIR(statbuf.st_mode)) {
            calculate_directory_size(full_path, total_size);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *target_dir = ".";
    long total_size = 0;

    // If a directory is specified as an argument, use it
    if (argc > 1) {
        target_dir = argv[1];
    }

    calculate_directory_size(target_dir, &total_size);
    printf("Total disk usage for '%s': %ld bytes\n", target_dir, total_size);

    return 0;
}
