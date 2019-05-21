//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>

typedef struct {
    unsigned int a:1;
    unsigned int b:2;
    unsigned int c:3;
} M;

int main()
{
    M k;
    k.a = 1;
    k.b = 1;
    k.c = 4;
    printf("a = %d\n", k.a);
    printf("b = %d\n", k.b);
    printf("c = %d\n", k.c);
    return 0;
}