//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>

int main(void)
{
    FILE *fp;
    char ch;
    const char *tmpfile = "/tmp/DUMMY.FIL";

    fp = fopen(tmpfile, "w");
    if (fp == NULL) {
        printf("Cannot open file: %s\n", tmpfile);
        return 0;
    }

    ch = getc(fp);
    if (ferror(fp)) {
        printf("Error reading from %s\n", tmpfile);
        clearerr(fp);
    }
    fclose(fp);
    return 0;
}
