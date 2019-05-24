//
// Created by YANHAI on 2019/5/24.
//

/*
 * 两种方式运行对比：
 * 1) ./dm04_fork3
 * 2) ./dm04_fork3 > test.txt && cat test.txt
 * 第2种运行方式，会多打印一行 `before fork!`，
 * 解释：
 *   1.调用fork函数后，父进程打开的文件描述符都被复制到子进程中。
 *     在重定向父进程的标准输出时，子进程的标准输出也会被重定向。
 *   2.write函数是系统调用，不带缓冲。
 *   3.标准I/O库是带缓冲的，当以交互方式运行程序时，标准I/O库是行缓冲的，否则它是全缓冲的。
 * 调用printf后，立即调用fflush函数会立即刷新缓冲区，2种运行方式打印就是一样的了。
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <memory.h>

int main()
{
    pid_t pid;
    size_t length;
    char buf[] = "a write to stdout\n";
    size_t buf_len = strlen(buf);

   length = write(STDOUT_FILENO, buf, buf_len);
   if (length != buf_len) {
       printf("write error!\n");
   }

    printf("before fork!\n");
//    fflush(stdout);   // 如果这里刷新缓冲区，2种运行方式就是一样的了。

    pid = fork();
    if (pid < 0) {
        printf("fork error\n");
        return 0;
    } else if (pid == 0) {
        printf("This is son process.\n");
    } else {
        sleep(1);
        printf("This is father process.\n");
    }
    return 0;
}
