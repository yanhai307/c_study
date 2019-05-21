//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>

int main(void)
{
    FILE *fp_read, *fp_write;
    char string1[100];
    const char *tmpsrc = "/tmp/src.txt";
    const char *tmpdst = "/tmp/dst.txt";

    if ((fp_read = fopen(tmpsrc, "r+")) == NULL) {
        printf("Cannot open file: %s\n", tmpsrc);
        return 0;
    }
    if ((fp_write = fopen(tmpdst, "w+")) == NULL) {
        printf("Cannot open file: %s\n", tmpsrc);
        fclose(fp_read);
        return 0;
    }

    fgets(string1, 10, fp_read);
    printf("%s\n", string1);
    fputs(string1, fp_write);

    fclose(fp_read);
    fclose(fp_write);
    return 0;
}