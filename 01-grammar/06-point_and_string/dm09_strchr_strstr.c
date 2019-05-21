//
// Created by YANHAI on 2019/5/21.
//

#include <string.h>
#include <stdio.h>

int main()
{
    char str1[20] = "hello $#$ world";
    char ch = '$';
    char str2[20] = "$#$";
    char *result;

    result = strchr(str1, ch);
    if (result != NULL) {
        printf("%s\n", result);
        printf("%d\n", result - str1);
    } else {
        printf("在字符串%s中没有找到字符%c\n",str1, ch);
    }

    result = strstr(str1, str2);
    if (result != NULL) {
        printf("%s\n", result);
        printf("%d\n", result - str1);
    } else {
        printf("在字符串%s中没有找到字符串%s\n",str1, str2);
    }

    return 0;
}
