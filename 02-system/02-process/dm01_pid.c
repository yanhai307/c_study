//
// Created by YANHAI on 2019/5/24.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid, ppid, pgid;

    pid = getpid();
    printf("pid = %d\n", pid);

    ppid = getppid();
    printf("ppid = %d\n", ppid);

    pgid = getpgid(pid);
    printf("pgid = %d\n", pgid);

    return 0;
}