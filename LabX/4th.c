#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("pids.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) { // Child
        dprintf(fd, "Child PID: %d\n", getpid());
    } else { // Parent
        dprintf(fd, "Parent PID: %d\n", getpid());
    }

    close(fd);
    return 0;
}
