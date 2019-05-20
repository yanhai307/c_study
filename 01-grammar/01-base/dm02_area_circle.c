//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

int main(void)
{
    float r = 0, area_circle = 0;
    printf("请输入圆的半径:\n");
    scanf("%f", &r);
    area_circle = 3.14f * r * r;
    printf("圆的面积为:%f\n", area_circle);
    return 0;
}
