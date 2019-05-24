//
// Created by YANHAI on 2019/5/24.
//

#include <stdio.h>
#include <unistd.h>

int main()
{
    // 第1个是可执行文件(必须指定路径)，
    // 第2个参数是进程名字，被执行的进程启动后，ps看到的进程名字
    // 从第3参数个开始，到NULL结束，均为传给新进程的参数（命令行参数）
    execl("/bin/ls", "ls", "-a", "-l", "-h", NULL);
    perror("execl: ");
    return 0;
}
