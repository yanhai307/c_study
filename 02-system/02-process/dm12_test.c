//
// Created by YANHAI on 2019/5/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("USER=%s\n", getenv("USER"));
    printf("GONGSI=%s\n", getenv("GONGSI"));
    return 0;
}