
#include "get_next_line.h"

int lastline(char **line, char *p)
{
    *line = ft_strdup(p);
    return(0);
}
int get_next_line(char **line, int fd)
{
    char *buff;
    static char *p;     
    int i;
    int j;

    buff = NULL;
    if (!p)
        p = ft_strdup("");
    while(!(ft_strchr(p, '\n')))
    {
        buff = malloc(BUFFER_SIZE);
        j = read(fd, buff, BUFFER_SIZE);
        buff[j] = '\0';
        if (j == 0 || buff[0] == '\0')
            return(lastline(line, p));
        if (ft_strchr(buff, '\n'))
            break;
        buff = ft_strjoin(p, buff);
        p = ft_strdup(buff);
        free(buff);
    }
    if(buff)
        buff = ft_strjoin(p, buff);
    else
    {
        buff = ft_strdup(p);
    }

    i = 0;
    while(!(ft_strchr("\n", buff[i])))
        i++;
    p = ft_substr(buff, i + 1, ft_strlen(buff) - i + 1);
    *line = ft_substr(buff, 0, i);
    return(1);
}

// int main()
// {
//     char *line;
//     int fd = open("text.txt", O_RDWR);
//     while(get_next_line(&line, fd))
//     {
//            printf("line is : %s\n", line);
//     }
//     // printf("line is : %s\n", line);
//     get_next_line(&line, fd);
//     printf("line is : %s\n", line);
// }