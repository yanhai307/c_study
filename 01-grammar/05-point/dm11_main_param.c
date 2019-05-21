//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    printf("argc=%d\n", argc);
    for (i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    return 0;
}