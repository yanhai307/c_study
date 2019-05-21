//
// Created by YANHAI on 2019/5/21.
//

#include  <stdio.h>
#include  <string.h>

void fun(char *str)
{
    char t = 0;
    char *s1 = str;
    char *s2 = str;
    while (*s2++ != '\0');
    s2 -= 2;
    while (s1 < s2) {
        t = *s1;
        *s1 = *s2;
        *s2 = t;
        s1++;
        s2--;
    }
}

int main(void)
{
    char str[] = "1234567";
    fun(str);
    puts(str);
    return 0;
}
