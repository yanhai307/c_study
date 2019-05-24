//
// Created by YANHAI on 2019/5/24.
//

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *arg[] = {"ls", "-a", "-l", "-h", NULL};
    execvp("ls", arg);
    perror("execvp: ");
}