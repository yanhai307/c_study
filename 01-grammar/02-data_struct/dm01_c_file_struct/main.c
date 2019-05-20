//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>        //包含系统头文件
#include <math.h>
#include "sub_func.h"    //包含自写的头文件

int main(void)
{
    float num_test_1 = 2, num_test_2 = 4;

    printf("My SunFunction:\n");
    printf("-------------------------------------------------\n");
    printf("the sum of %f and %f is:%f\n", num_test_1, num_test_2, my_sum(num_test_1, num_test_2));    //求a b之和
    printf("the dec of %f and %f is:%f\n", num_test_1, num_test_2, my_dec(num_test_1, num_test_2));    //求a b之差
    printf("the mux of %f and %f is:%f\n", num_test_1, num_test_2, my_mux(num_test_1, num_test_2));   //求a b之积
    printf("the dvi of %f and %f is:%f\n", num_test_1, num_test_2, my_dvi(num_test_1, num_test_2));   //求a b之商

    printf("\nThe system lib:\n");
    printf("-------------------------------------------------\n");
    printf("the sin of %f is: %f\n", num_test_1, sin(num_test_1));                //求a的正弦值
    printf("the atan of %f is: %f\n", num_test_1, atan(num_test_1));            //求a的反余弦值
    printf("the %f of %f  pow is: %f\n", num_test_1, num_test_2, pow(num_test_1, num_test_2));        //求a的b次幂
    printf("the sqrt of %f is: %f\n", num_test_2, sqrt(num_test_2));            //求a的平方根

    return 0;
}
