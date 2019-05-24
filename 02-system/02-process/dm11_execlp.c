//
// Created by YANHAI on 2019/5/24.
//

#include <stdio.h>
#include <unistd.h>

int main()
{
    // 与execl的区别，是第1个参数，
    //   可执行文件可以不指定路径，从系统环境变量搜索
    execlp("ls", "ls", "-a", "-l", "-h", NULL);
    perror("execlp: ");
    return 0;
}