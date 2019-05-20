//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

int sum(int m)
{
    int i = 0, n = 0;
    for (i = 1; i <= m; i += 1)
        n += i;
    printf("The sum of 1-%d is %d\n", m, n);
    return 0;
}

int main(int argc, char *argv[])
{
    int i = 0, n = 0;
    sum(50);
    for (i = 1; i <= 50; i += 1)
        n += i;
    printf("The sum of 1-%d is %d\n", 50, n);
    return 0;
}