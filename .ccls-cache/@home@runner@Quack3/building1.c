#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status;

    // Create the first child process
    pid1 = fork();
    if (pid1 == -1) {
        printf("Failed to create child process 1.\n");
        exit(1);
    } else if (pid1 == 0) {  // Child process 1
        execl("./program1", "program1", NULL);
        printf("Failed to execute program1.\n");
        exit(1);
    }

    // Wait for child process 1 to finish
    waitpid(pid1, &status, 0);

    // Create the second child process
    pid2 = fork();
    if (pid2 == -1) {
        printf("Failed to create child process 2.\n");
        exit(1);
    } else if (pid2 == 0) {  // Child process 2
        execl("./program2", "program2", NULL);
        printf("Failed to execute program2.\n");
        exit(1);
    }

    // Wait for child process 2 to finish
    waitpid(pid2, &status, 0);

    // Create the third child process
    pid_t pid3 = fork();
    if (pid3 == -1) {
        printf("Failed to create child process 3.\n");
        exit(1);
    } else if (pid3 == 0) {  // Child process 3
        execl("./program3", "program3", NULL);
        printf("Failed to execute program3.\n");
        exit(1);
    }

    // Wait for child process 3 to finish
    waitpid(pid3, &status, 0);

    printf("Building1 is drawn successfully.\n");
    exit(0);
}
