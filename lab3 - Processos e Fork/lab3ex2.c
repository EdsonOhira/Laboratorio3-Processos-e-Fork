#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        printf("Sou o processo filho. PID do filho: %d\n", getpid());
        for (int i = 0; i < 5; i++) {
            printf("Mensagem %d do processo filho\n", i + 1);
        }
        exit(EXIT_SUCCESS);
    } else {
        printf("Sou o processo pai. PID do pai: %d\n", getpid());
        printf("PID do processo filho: %d\n", pid);
        wait(NULL);
        printf("O processo filho terminou sua execu��o.\n");
    }
    return 0;
}
