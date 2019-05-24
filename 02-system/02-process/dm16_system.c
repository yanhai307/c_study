//
// Created by YANHAI on 2019/5/24.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int status;

    printf("before call command `ls -alh`\n");
    status = system("ls -alh");
    printf("after call command `ls -alh`\n");

    if (WIFEXITED(status)) {
        printf("The exit status is %d\n", status);
    } else {
        // 这里的异常，是system调用异常，不是system执行的命令异常
        printf("abnormal exit\n");
    }

    return 0;
}