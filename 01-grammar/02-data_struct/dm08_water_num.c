//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

int main()
{
    int a, b, c, i;
    for (i = 0; i <= 999; i++) {
        a = (i / 100) % 10;
        b = (i / 10) % 10;
        c = (i / 1) % 10;
        if (i == a * a * a + b * b * b + c * c * c)
            printf("%d  ", i);
    }
    printf("\n");

    i = 789;
    a = (i / 100) % 10;
    b = (i / 10) % 10;
    c = (i / 1) % 10;
    printf("a=%d, b=%d, c=%d\n", a, b, c);

    return 0;
}
