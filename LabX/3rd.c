#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signo) {
    printf("Process %d received signal %d\n", getpid(), signo);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) { // Child
        signal(SIGUSR1, signal_handler);
        pause(); // Wait for signal
    } else { // Parent
        sleep(1); // Give child time to set up signal handler
        kill(pid, SIGUSR1);
    }
    return 0;
}
