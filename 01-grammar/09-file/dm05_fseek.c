//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>

struct stu {
    char name[10];
    int num;
    int age;
} boya[2], boyb;

int main()
{
    FILE *fp;
    int i;
    const char *tmpfile = "/tmp/test.txt";

    if ((fp = fopen(tmpfile, "wb+")) == NULL) {
        printf("Cannot open file: %s\n", tmpfile);
        return 0;
    }
    printf("请输入 name num age\n");
    for (i = 0; i < 2; i++)
        scanf("%s %d %d", boya[i].name, &boya[i].num, &boya[i].age);
    fwrite(boya, sizeof(struct stu), 2, fp);
    fseek(fp, sizeof(struct stu), SEEK_SET);
    fread(&boyb, 1, sizeof(struct stu), fp);
    printf("%s %d %d\n", boyb.name, boyb.num, boyb.age);
    fclose(fp);
    return 0;
}
