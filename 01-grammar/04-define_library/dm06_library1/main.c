//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>
#include "library.h"

int main(int argc, char *argv[])
{
    int a = 10, b = 20, max_num, min_num;
    max_num = max(a, b);
    min_num = min(a, b);

    printf("max = %d\n", max_num);
    printf("min = %d\n", min_num);
}