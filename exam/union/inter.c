#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
char *ft_strchr(char *str, int a);
int ft_strlen(char *str);

int main(int ac, char **av)
{
    int i;
    int j;
    char *buf;
    int e;

    buf = malloc(ft_strlen(av[2]));
    buf[0] = '\0';
    e = 0;
    if( ac != 3)
        write(1, "\n", 1);
    else
    {
        while(av[1][j])
        {
            if(ft_strchr(av[2],av[1][j]) && !ft_strchr(buf, av[1][j]))
            {
                buf[e++] = av[1][j++];
                buf[e] = '\0';
            }
            else
                j++;
        }
    }
    printf("|%s|", buf);
}
