//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>
#include "func.h"

extern int max(int x, int y);

extern int min(int x, int y);

int main(void)
{
    int a = 10, b = 20, max_num, min_num;
    max_num = max(a, b);
    min_num = min(a, b);
    printf("max_num=%d\n", max_num);
    printf("min_num=%d\n", min_num);
    return 0;
}

