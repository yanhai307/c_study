//
// Created by YANHAI on 2019/5/20.
//

#include "stdio.h"

/**
 * 交换两个变量
 * @param a 第1个变量的地址
 * @param b 第2个变量的地址
 */
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * 冒泡排序
 * @param k
 * @param n
 */
void bubblesort(int k[], int n)
{
    int i, j;
    int flag = 1, cont = 0;

    for (i = 0; i < n && flag == 1; i++)    //控制每趟往前推一个，即少比较一次
    {
        flag = 0;    //加上flag， 如果剩下的数据没有发生交换，则表示已经是顺序的了，就可以终止排序了
        for (j = 0; j < n - i - 1; j++) //从第一个开始，不断与相邻的值比较，并交换最值，一直推到最后，形如冒泡
        {
            cont++;
            if (k[j] < k[j + 1]) {
                swap(&k[j + 1], &k[j]);
                flag = 1;
            }
        }
    }

    printf("\n循环比较次数：%d\n", cont);
}

int main1()
{
    int i, a[10] = {2, 5, 6, 3, 7, 8, 12, 9, 1, 0};

    printf("The data array is\n");
    for (i = 0; i < 10; i++)                        /*显示原序列之中的元素*/
        printf("%d ", a[i]);

    bubblesort(a, 10);                              /*执行冒泡排序*/
    printf("The result of bubble sorting for the array is\n");
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);                        /*输出排序后的结果*/
    printf("\n\n");

    return 0;
}

int main2()
{
    int i, a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("The data array is\n");
    for (i = 0; i < 10; i++)                        /*显示原序列之中的元素*/
        printf("%d ", a[i]);

    bubblesort(a, 10);                              /*执行冒泡排序*/
    printf("The result of bubble sorting for the array is\n");
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);                        /*输出排序后的结果*/
    printf("\n\n");

    return 0;
}


int main3()
{
    int i, a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("The data array is\n");
    for (i = 0; i < 10; i++)                        /*显示原序列之中的元素*/
        printf("%d ", a[i]);

    bubblesort(a, 10);                              /*执行冒泡排序*/
    printf("The result of bubble sorting for the array is\n");
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);                        /*输出排序后的结果*/
    printf("\n\n");

    return 0;
}


int main()
{
    main1();
    main2();
    main3();
    return 0;
}
