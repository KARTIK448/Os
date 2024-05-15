#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


#define BUFFER_SIZE 1024

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Child process
        // Close the unused write end of the pipe
        close(pipefd[1]);
        
        // Read from the pipe
        read(pipefd[0], buffer, BUFFER_SIZE);
        printf("Child Process: Received message from parent: %s\n", buffer);
        
        // Close the read end of the pipe
        close(pipefd[0]);
    } else {  // Parent process
        // Close the unused read end of the pipe
        close(pipefd[0]);
        
        // Write to the pipe
        char *message = "Hello from Parent Process!";
        write(pipefd[1], message, strlen(message)+1);
        
        // Close the write end of the pipe
        close(pipefd[1]);
    }

    return 0;
}