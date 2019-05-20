//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

int main()
{    //0101 0101
    unsigned char a1 = 0x55, a2 = 0x55, a3 = 0x55, a4 = 0x55;
    unsigned char a5 = 0x55, a6 = 0x55, a7 = 0x55;
    printf("a1=%0x\n", a1); // 0x55
    a2 = a2 & 0xf0;         // 0x50
    printf("a2=%0x\n", a2);
    a3 = a3 | 0x0f;         // 0x5f
    printf("a3=%0x\n", a3);
    a4 = a4 ^ 0x0f;         // 0x5a
    printf("a4=%0x\n", a4);
    a5 = ~a5;               // 0xaa
    printf("a5=%0x\n", a5);
    a6 = a6 >> 2;           // 0x15
    printf("a6=%0x\n", a6);
    a7 = a7 << 2;           // 0x54
    printf("a7=%0x\n", a7);
    return 0;
}
