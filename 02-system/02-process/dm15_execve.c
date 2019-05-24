//
// Created by YANHAI on 2019/5/24.
//

// 请先编译 dm12_test.c

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *arg[] = {"dm12_test", NULL};
    char *env[] = {"USER=ME", "GONGSI=AIPU", NULL};

    // 只有execve函数为真正的系统调用函数（内核提供的接口）
    // 其他5个都是在此基础经过封装的库函数
    execve("./dm12_test", arg, env);
    perror("execve: ");
    return 0;
}

/**
 * 一个进程调用exec后，除了进程ID，进程还保留了下列特征不变：
 * 1. 父进程号
 * 2. 进程组好
 * 3. 控制终端
 * 4. 根目录
 * 5. 当前工作目录
 * 6. 进程信号屏蔽集
 * 7. 未处理信号
 */
