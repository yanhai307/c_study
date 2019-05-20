//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

static unsigned char get_bit(unsigned char num, int bit)
{
    if (num & (1 << bit))
        return 1;
    return 0;
}

static void print_bit(unsigned char num)
{
    int i;
    for (i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", get_bit(num, i));
    }
    printf("\n");
}

int main()
{
    unsigned char a = 0x55;

    printf("a1=0x%x\n", a);
    print_bit(a);
    printf("\n");

    // 将1 5 7 位置1
    a |= (1 << 1) | (1 << 5) | (1 << 7);
    print_bit(a);
    printf("\n");

    // 将 2 3 6 位清零
    a &= ~((1 << 2) | (1 << 3) | (1 << 6));
    print_bit(a);
    printf("a2=0x%x\n", a);
    return 0;
}
