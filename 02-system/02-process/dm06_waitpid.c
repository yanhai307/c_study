//
// Created by YANHAI on 2019/5/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork: ");
        return 0;
    } else if (pid == 0) {
        int i;
        for (i = 0; i < 5; i++) {
            printf("This is son process\n");
            sleep(1);
        }
        _exit(2);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) != 0) {
            printf("son process return %d\n", WEXITSTATUS(status));
        }

        printf("This is father process\n");
    }
    return 0;
}