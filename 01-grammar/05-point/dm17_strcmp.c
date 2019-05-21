//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>

int _strcmp(char *s1, char *s2)
{
    while (*s1 || *s2) {
        if ((*s1 - *s2) > 0)
            return 1;
        else if ((*s1 - *s2) < 0)
            return -1;
        else {
            s1++;
            s2++;
        }
    }
    return 0;
}

int main()
{
    char *str1 = "hello world";
    char *str2 = str1;
    char *str3 = "hello c";

    if (_strcmp(str1, str2) == 0) {
        printf("%s == %s\n", str1, str2);
    } else {
        printf("%s != %s\n", str1, str2);
    }
    if (_strcmp(str1, str3) == 0) {
        printf("%s == %s\n", str1, str3);
    } else {
        printf("%s != %s\n", str1, str3);
    }
}