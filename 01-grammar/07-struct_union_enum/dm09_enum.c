//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>

enum weekday {
    sun = 2, mon, tue, wed, thu, fri, sat
} a, b, c;

enum bool {
    flase, true
} bl;

int main()
{
    a = sun;
    b = mon;
    c = tue;
    printf("%d,%d,%d", a, b, c);

    bl = true;
    if (bl == 1)
        printf("bl为真\n");
    return 0;
}
