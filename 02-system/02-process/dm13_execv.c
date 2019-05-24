//
// Created by YANHAI on 2019/5/24.
//

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *arg[] = {"ls", "-a", "-l", "-h", NULL};
    // 与execl的区别，
    // 进程名称和进程参数放在了一个指针数组中，数组最后一个成员必须为NULL
    execv("/bin/ls", arg);
    perror("execv: ");
    return 0;
}