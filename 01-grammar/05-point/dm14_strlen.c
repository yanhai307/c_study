//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>

int _strlen1(const char *sc)
{
    int num = 0;
    while (*sc != '\0') {
        sc++;
        num++;
    }
    return num;
}


int _strlen2(const char *s)
{
    const char *sc;
    for (sc = s; *sc != '\0'; ++sc);
    return sc - s;
}

int main()
{
    char *str1 = "hello world";
    printf("%s strlen: %d\n", str1, _strlen1(str1));
    printf("%s strlen: %d\n", str1, _strlen2(str1));
    return 0;
}