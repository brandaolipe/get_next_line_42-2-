#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2;
    char *line;
    fd1 = open("arquivo1.txt", O_RDONLY);
    fd2 = open("arquivo2.txt", O_RDONLY);
    line = get_next_line(fd1);
    //fd = open("arquivo1.txt", O_RDONLY);
    //fd = 0;
    //fd = 9;
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd2);
        printf("%s", line);
        free(line);
        line = get_next_line(fd1);
    }
    close(fd1);
    close(fd2);
    return (0);
}
