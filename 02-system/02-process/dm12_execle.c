//
// Created by YANHAI on 2019/5/24.
//


// 请先编译 dm12_test.c

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *env[] = {"USER=ME", "GONGSI=AIPU", NULL};

    // 在execl的基础上，增加了 传入环境变量的功能
    // 注意 第1个参数，必须指定路径
    execle("./dm12_test", "dm12_test", NULL, env);
    perror("execle: ");
    return 0;
}