//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>

int main(void)
{
    FILE *fp;
    char ch;
    const char *tmpfile = "test.txt";

    fp = fopen(tmpfile, "r+");
    if (fp == NULL) {
        printf("Cannot open file: %s\n", tmpfile);
        return 0;
    }
    while (1) {
        ch = fgetc(fp);
        if (feof(fp) != 0)
            break;
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}