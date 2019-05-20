//
// Created by YANHAI on 2019/5/20.
//

#include <stdio.h>

__attribute((constructor)) void before_main(void)
{
    printf("%s\n",__FUNCTION__);
}

__attribute((destructor)) void after_main(void)
{
    printf("%s\n",__FUNCTION__);
}

int main(int argc, char ** argv)
{
    printf("%s\n", "in main");
    return 0;
}