//
// Created by YANHAI on 2019/5/21.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int count, *array, n;

    printf("请输入要申请数组的个数:\n");
    scanf("%d", &n);
    array = (int *) malloc(n * sizeof(int));
    if (array == NULL) {
        printf("申请空间失败!\n");
        return -1;
    }
    //将申请到空间清0
    memset(array, 0, sizeof(int) * n);

    for (count = 0; count < n; count++) /*给数组赋值*/
        array[count] = count;

    for (count = 0; count < n; count++) /*打印数组元素*/
        printf("%d ", array[count]);
    printf("\n");
    free(array);

    return 0;
}
