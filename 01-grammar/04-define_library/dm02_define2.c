//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

// 宏的二义性

#define SQ_1(y) (y)*(y)
#define SQ_2(y)  y*y

int main()
{
    int a = 0, num_1 = 0, num_2 = 0;
    printf("请输入一个整数: ");
    scanf("%d", &a);
    num_1 = SQ_1(a + 1);    //num_1 = (a+1)*(a+1);
    num_2 = SQ_2(a + 1);    //num_2 = a+1*a+1;
    printf("num_1 = %d\n", num_1);
    printf("num_2 = %d\n", num_2);
    return 0;
}