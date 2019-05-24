//
// Created by YANHAI on 2019/5/24.
//

/*
 * 调用 _exit()函数结束进程时，不会调用atexit注册的函数。
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clear_fun1(void)
{
    printf("perform %s\n", __FUNCTION__);
}

void clear_fun2(void)
{
    printf("perform %s\n", __FUNCTION__);
}

void clear_fun3(void)
{
    printf("perform %s\n", __FUNCTION__);
}

int main()
{
    atexit(clear_fun1);
    atexit(clear_fun2);
    atexit(clear_fun3);
    printf("process exit 3 sec later!!!\n");
    sleep(3);

    //    _exit(0);
    return 0;
}