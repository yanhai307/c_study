//
// Created by YANHAI on 2019/5/24.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork: \n");
    } else if (pid == 0) {
        while (1) {
            printf("This is son process, this pid is %d\n", getpid());
            sleep(1);
        }
    } else {
        while (1) {
            printf("This is father process, this pid is %d\n", getpid());
            sleep(1);
        }
    }
    return 0;
}