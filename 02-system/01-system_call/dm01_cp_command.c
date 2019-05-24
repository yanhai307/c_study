//
// Created by YANHAI on 2019/5/24.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd_src, fd_dest;
    char buf[1024];
    size_t ret;
    if (argc != 3) {
        printf("参数不够\n");
        return 0;
    }
    fd_src = open(argv[1], O_RDONLY);
    if (fd_src < 0) {
        perror("open src");
        return 0;
    }
    fd_dest = open(argv[2], O_WRONLY | O_CREAT, 0666);
    if (fd_dest < 0) {
        perror("open dest");
        close(fd_src);
        return 0;
    }
    while (1) {
        ret = read(fd_src, buf, sizeof(buf));
        if (ret <= 0)
            break;
        write(fd_dest, buf, ret);
    }
    close(fd_src);
    close(fd_dest);
    return 0;
}
