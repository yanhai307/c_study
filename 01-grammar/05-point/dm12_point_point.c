//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetMemory1(char *p, int num)
{
    p = (char *) malloc(100);
}

void GetMemory2(char **p, int num)
{
    *p = (char *) malloc(num);
}

int main(void)
{
    char *str = NULL;
    GetMemory1(str, 100);   // str仍为null
    GetMemory2(&str, 100);
    strcpy(str, "hello world");
    printf("%s\n", str);
    free(str);
    return 0;
}
