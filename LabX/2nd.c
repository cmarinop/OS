#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0) { // Child
        close(fd[0]);
        char message[] = "Hello from child!";
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    } else { // Parent
        close(fd[1]);
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}
