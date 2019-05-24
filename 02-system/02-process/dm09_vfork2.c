//
// Created by YANHAI on 2019/5/24.
//

/*
 * fork和vfork函数的区别
 * 2. vfork和fork一样都是创建一个子进程，但它并不将父进程的地址空间完全复制到子进程中，
 *    因为子进程会立即调用exec(或exit)，于是也就不访问该地址空间。
 *    相反，在子进程中调用exec或exit之前，它在父进程的地址空间中运行，在exec之后子进程会有自己的进程空间。
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int num = 10;

int main()
{
    pid_t pid;
    int var = 9;

    pid = vfork();
    if (pid < 0) {
        perror("vfork: ");
        return 0;
    }
    else if (pid == 0) {
        num++;
        var++;

        printf("This is son process, num=%p,var=%p\n", &num, &var);
        printf("This is son process, num=%d,var=%d\n", num, var);
        _exit(2);
    } else {
        printf("This is father process, num=%p,var=%p\n", &num, &var);
        printf("This is father process, num=%d,var=%d\n", num, var);
    }

    printf("common code area, exit!\n");
    return 0;
}
