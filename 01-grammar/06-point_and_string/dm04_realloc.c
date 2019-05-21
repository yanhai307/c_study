//
// Created by YANHAI on 2019/5/21.
//

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i;

    int *pn = (int *) malloc(5 * sizeof(int));
    if (pn == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        printf("请输入第%d个整数: ", i + 1);
        scanf("%d", &pn[i]);
    }

    int *pn2 = (int *) realloc(pn, 10 * sizeof(int));
    if (pn2 == NULL) {
        printf("realloc failed\n");
        free(pn);
        return 1;
    } else {
        pn = pn2;
    }

    for (i = 5; i < 10; i++) {
        printf("请输入第%d个整数: ", i + 1);
        scanf("%d", &pn[i]);
    }

    printf("输入的整数为：\n");
    for (i = 0; i < 10; i++)
        printf("%d ", pn[i]);

    free(pn);
    return 0;
}