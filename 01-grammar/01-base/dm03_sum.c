//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

int sum(int x, int y)
{
    int z;
    z = x + y;
    return z;
}

int main(void)
{
    int sum_num, a = 20, b = 10;
    sum_num = sum(a, b);
    printf("%d + %d = %d\n", a, b, sum_num);
    return 0;
}
