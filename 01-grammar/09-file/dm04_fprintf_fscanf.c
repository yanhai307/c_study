//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>

int main(void)
{
    FILE *fp;
    char ch1 = 'a', ch2;
    int num1 = 50, num2;
    const char *tmpfile = "/tmp/test.txt";

    char string1[20] = "hello", string2[20];
    float score1 = 85.5, score2;

    if ((fp = fopen(tmpfile, "wb+")) == NULL) {
        printf("Cannot open file: %s\n", tmpfile);
        return 0;
    }
    fprintf(fp, "%c %d %s %f\n", ch1, num1, string1, score1);
    printf("1: %c %d %s %f\n", ch1, num1, string1, score1);
    rewind(fp);
    fscanf(fp, "%c %d %s %f\n", &ch2, &num2, string2, &score2);
    printf("2: %c %d %s %f\n", ch2, num2, string2, score2);
    fclose(fp);
    return 0;
}
