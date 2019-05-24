//
// Created by YANHAI on 2019/5/24.
//

/*
 * fork和vfork函数的区别
 * 1. vfork保证子进程先运行，在它调用exec或exit后，父进程才可能被调度运行。
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = vfork();
    if (pid < 0) {
        perror("vfork: \n");
        return 0;
    } else if (pid == 0) {
        int i;
        for (i =0; i < 5; i++) {
            printf("This is son process, this pid is %d\n", getpid());
            sleep(1);
        }
        _exit(0);
    } else {
        int i;
        for (i =0; i < 5; i++) {
            printf("This is father process, this pid is %d\n", getpid());
            sleep(1);
        }
    }
    return 0;
}