//
// Created by YANHAI on 2019/5/24.
//

// 实现system函数

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int my_system(const char *cmd)
{
    int status = 0;
    pid_t pid;

    if (cmd == NULL)
        return 1;

    pid = fork();
    if (pid < 0) {
        perror("fork: ");
        return -1;
    } else if (pid == 0) {
        execl("/bin/sh", "sh", "-c", cmd, NULL);
        _exit(127);
    } else {
        while (waitpid(pid, &status, WAIT_MYPGRP) < 0) {
            if (errno != EINTR) {
                status = -1;
                break;
            }
        }
    }

    return status;
}

int main()
{
    int status;

    status = my_system("ls -alh");
    if (WIFEXITED(status)) {
        printf("The exit status is %d\n", status);
    } else {
        printf("abnormal exit\n");
    }

    return 0;
}
