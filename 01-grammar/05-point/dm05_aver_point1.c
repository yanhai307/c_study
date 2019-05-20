//
// Created by YANHAI on 2019/5/20.
//

#include<stdio.h>

int main()
{
    char *name[] = {"Follow me", "BASIC", "GreatWall", "FORTRAN", "Computer design"};
    int i;
    for (i = 0; i < 5; i++) {
        printf("%s\n", name[i]);
    }
    return 0;
}
