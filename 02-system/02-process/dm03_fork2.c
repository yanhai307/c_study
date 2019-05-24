//
// Created by YANHAI on 2019/5/24.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int num = 10;

int main()
{
    pid_t pid;
    int var = 9;

    pid = fork();
    if (pid < 0) {
        perror("fork: ");
        return 0;
    }
    else if (pid == 0) {
        num++;
        var++;

        printf("This is son process, num=%p,var=%p\n", &num, &var);
        printf("This is son process, num=%d,var=%d\n", num, var);
    } else {
        sleep(1);
        printf("This is father process, num=%p,var=%p\n", &num, &var);
        printf("This is father process, num=%d,var=%d\n", num, var);
    }

    printf("common code area, exit!\n");
    return 0;
}

/*
 * 结果打印，父子进程中的变量的地址是一样的，但是变量值是不同的。
 *
 * 解释：
 *  虽然两个指针的值相同，但他们是不同进程空间的，所以会映射到不同的物理内存。
 *  子进程复制了父进程的数据之后，两者就完全没有关系了。
 */
