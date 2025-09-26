#include "get_next_line.h"
// #include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char    *str;

    fd = open("arquivo1.txt", O_RDONLY);
    //fd = open("arquivo1.txt", O_RDONLY);
    //fd = 0;
    //fd = 9;
    while ((str = get_next_line(fd)))
    {
        printf("%s", str);
        free(str);
    }
    close(fd);
    return (0);
}
