//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>

int big_endian(void)
{
    union {
        long l;
        char c[sizeof(long)];
    } u;

    u.l = 1;
    return (u.c[sizeof(long) - 1] == 1);
}

int big_endian2()
{
    short int x;
    char x0;

    x = 0x1122;

    x0 = ((char *) &x)[0];  //低地址单元
    return x0 == 0x11;
}

int big_endian3()
{
    union {
        int a;
        char b;
    } c;
    c.a = 1;
    return (c.b != 1);
}

int main()
{
    if (big_endian())
        printf("big endian\n");
    else
        printf("little endian\n");

    if (big_endian2())
        printf("big endian\n");
    else
        printf("little endian\n");

    if (big_endian3())
        printf("big endian\n");
    else
        printf("little endian\n");
    return 0;
}