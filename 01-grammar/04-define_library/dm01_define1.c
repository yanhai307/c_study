//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

#define PI 3.1415f

int main()
{
    float L, S, R, V;
    printf("Input Radius>> ");
    scanf("%f", &R);
    L = 2.0f * PI * R;
    S = PI * R * R;
    V = 4.0f / 3 * PI * R * R * R;
    printf("圆的周长：%.4f, 圆的面积：%.4f, 球的体积：%.4f\n", L, S, V);
    return 0;
}
