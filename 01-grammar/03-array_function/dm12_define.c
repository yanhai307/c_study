//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

#define SUM(a, b)    (a)+(b)
#define DEC(a, b)    (a)-(b)
#define MUX(a, b)    (a)*(b)
#define DIV(a, b)    (a)/(b)

int main()
{
    int a, b;
    printf("please input two number(a and b):\n");
    scanf("%d %d", &a, &b);

    printf("sum = %d\n", SUM(a, b));
    printf("dec = %d\n", DEC(a, b));
    printf("mux = %d\n", MUX(a, b));
    printf("div = %d\n", DIV(a, b));
    return 0;
}
