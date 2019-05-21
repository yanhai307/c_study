//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>
#include <string.h>

int main()
{
    char dest1[20] = "123456789";
    char dest2[20] = "123456789";
    char dest3[20] = "123456789";
    char *src = "hello world";

    strcpy(dest1, src);
    printf("dest1=%s\n", dest1);

    strncpy(dest2, src, 5);
    printf("dest2=%s\n", dest2);

    dest2[5] = '\0';
    printf("dest2=%s\n", dest2);

    // 资料上说的 strncpy '\0'不拷贝 是怎么理解的
    strncpy(dest3, "he\0llo", 5);
    printf("dest3=%s\n", dest3);
    printf("dest3=%s\n", dest3+3);

    return 0;
}
