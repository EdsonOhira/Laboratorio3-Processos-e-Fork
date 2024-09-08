#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        printf("Sou o processo filho. PID do filho: %d\n", getpid());
        printf("\nOi, eu sou um novo programa executado pelo Processo Filho, a seguir, estou listando os arquivos .c que est�o na pasta lab3 - Processos e Fork\n");
        execl("/bin/sh", "sh", "-c", "ls *.c", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        printf("\nSou o processo pai. PID do pai: %d\n", getpid());
        printf("PID do processo filho: %d\n", pid);
        int status;
        if (wait(&status) == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
        if (WIFEXITED(status)) {
            printf("O processo filho terminou com c�digo de sa�da %d.\n", WEXITSTATUS(status));
        } else {
            printf("O processo filho terminou de forma anormal.\n");
        }
    }
    return 0;
}

