//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

int max(int x, int y);

//int max(int ,int );

int main(void)
{
    int a = 10, b = 20, max_num;
    max_num = max(a, b);
    printf("max_num=%d\n", max_num);
    return 0;
}

int max(int x, int y)
{
    return x > y ? x : y;
}
