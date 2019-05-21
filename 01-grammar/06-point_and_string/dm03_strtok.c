//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "adc*fvcv!ebcy!!hghb**!dfg*casdert";
    char *str2 = "*!";
    char *p;
    int num = 0;

#if 1
    p = strtok(str1, str2);
    while (p != NULL) {
        printf("p[%d] = %s\n", num, p);
        num++;
        p = strtok(NULL, str2);
    }
#else
    char *src = str1;
    do {
        p = strtok(src, str2);
        src = NULL;
        if (p != NULL) {
            printf("p[%d] = %s\n", num++, p);
        }
    } while (p != NULL);
#endif

    return 0;
}
