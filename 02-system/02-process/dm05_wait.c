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
        printf("son process will exit, exit code is 2\n");
        _exit(2);
    } else {
        int status = 0;
        wait(&status);
        if (WIFEXITED(status) != 0) {
            printf("father process: son return %d\n", WEXITSTATUS(status));
        }
        printf("This is father process\n");
    }
    return 0;
}
