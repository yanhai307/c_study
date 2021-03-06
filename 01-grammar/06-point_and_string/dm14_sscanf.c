//
// Created by YANHAI on 2019/5/21.
//

/**
 * sscanf()的正则表达式是从头向后顺序查找匹配字符，找不到就返回错误，如下面的几个例子：
 * char src[] = "abcdefABCD123@456EFGghi";//一个buf只对应一个%，%*可以用多次
 * sscanf(src, "%[A-Z]", buf);//buf=空，遇到A-Z以外的字符就停止，%表示选择，%后面的表示条件，条件s表示任意字符
 * sscanf(src, "%[^A-Z]", buf);//buf=abcdef，^表示取反，即遇到A-Z之间的字符就结束
 * sscanf(src, "%[^A]", buf);//buf=abcdef，从左向右获取除A以外的字符，直到A结果
 * sscanf(src, "%*[^A]", buf);//buf=空，*表示后面匹配的字符不保存([^A]本应该是abcdef，但因加了*所以没有了即过滤掉了)
 * sscanf(src, "%*[^A]%s", buf);//buf=ABCD123@456EFGghi，s表示获取字符串，虽然前面没有保存字符，但后面的字符可以获得并保存
 * sscanf(src, "%*[^A]%[^@]", buf);//buf=ABCD123，直到遇到A并包含A结束
 * sscanf(src, "%*[^A]A%[^@]", buf);//buf=BCD123，直到遇到A但不包含A结束，A为定界符
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char buf[20];

    sscanf("1234 5678", "%*d %s", buf);
    printf("buf1=%s\n", buf);

    sscanf("12345678", "%4s", buf);
    printf("buf2=%s\n", buf);

    sscanf("123abcABC", "%[1-9a-z]", buf);
    printf("buf3=%s\n", buf);

    sscanf("123abcABC", "%[^A-Z]", buf);
    printf("buf4=%s\n", buf);

    sscanf("123456 abcdedf", "%[^ ]", buf);
    printf("buf5=%s\n", buf);
    return 0;
}