#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
            break;
        } else {
            printf("Parent Process: PID = %d\n", getpid());
        }
    }
    return 0;
}
