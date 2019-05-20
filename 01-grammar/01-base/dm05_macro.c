//
// Created by YANHAI on 2019/5/20.
//

/**
 * ANSI C 标准定义了以下6种可供C语言使用的预定义宏：
 * __LINE__ 在源代码中插入当前源代码行号
 * __FILE__ 在源代码中插入当前源代码文件名
 * __DATE__ 在源代码中插入当前编译日期〔注意和当前系统日期区别开来〕
 * __TIME__ 在源代码中插入当前编译时间〔注意和当前系统时间区别开来〕
 * __STDC__ 当要求程序严格遵循ANSIC标准时该标识符被赋值为1。
 * __cplusplus
 * 标识符__LINE__和__FILE__通常用来调试程序；
 * 标识符__DATE__和__TIME__通常用来在编译后的程序中加入一个时间标志，以区分程序的不同版本；
 * 当要求程序严格遵循ANSIC标准时，标识符__STDC__就会被赋值为1；
 * 当用C++编译程序编译时，标识符__cplusplus就会被定义。
 */

#include <stdio.h>

int sum(int x, int y)
{
    int z;
    z = x + y;
    printf("__FILE__: %s\n", __FILE__);
    printf("__LINE__: %d\n", __LINE__);
    printf("__FUNCTION__: %s\n", __FUNCTION__);
    printf("__DATE__: %s\n", __DATE__);
    printf("__TIME__: %s\n", __TIME__);
    printf("__STDC__: %d\n", __STDC__);
    return z;
}

int main(void)
{
    int sum_num, a = 20, b = 10;
    sum_num = sum(a, b);
    printf("%d + %d = %d\n", a, b, sum_num);
    return 0;
}
