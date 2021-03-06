//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

//数组指针
int a[3][5] = {
        {1,  3,  5,  7,  20},
        {9,  11, 13, 15, 21},
        {17, 19, 21, 23, 22}
};

int main()
{
    char i;
    int (*p)[5] = a;                //定义一个数组指针指向一个二维数组

    for (i = 0; i < 5; i++)            //采用数组指针打印二维数组的第一行
        printf("%d\n", *(p[0] + i));

    for (i = 0; i < 5; i++)            //采用数组指针打印二维数组的第二行
        printf("%d\n", *(p[1] + i));
    return 0;
}
