//
// Created by YANHAI on 2019/5/21.
//

#include<stdio.h>

//共用体
union xx {
    long int x;
    char y;
    int z;
} a = {10};

int main()
{
    a.x = 5;
    a.y = 6;
    a.z = 15;
    printf("%ld\n", a.x + a.y);

    a.x = 0x1234567887654321;
    printf("long: %#lx\n", a.x);
    printf("char: %#x\n", a.y);
    printf("int: %#x\n", a.z);
    return 0;
}
