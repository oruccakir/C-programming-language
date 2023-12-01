#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        // Error handling
        perror("fork");
        return 1;
    } else if (pid > 0) {
        // Parent process
        printf("Parent process (PID: %d)\n", getpid());
    } else {
        // Child process
        printf("Child process (PID: %d)\n", getpid());
    }

    return 0;
}
