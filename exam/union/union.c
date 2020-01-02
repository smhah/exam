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

    e = 0;
    if(ac != 3)
        write(1, "\n", 1);
    else
    {
        buf = malloc(ft_strlen(av[1]) + ft_strlen(av[2]) + 1);
        i = 1;
        while(i <= 2)
        {
            j = 0;
            while(av[i] && av[i][j])
            {
                if(e == 0)
                {
                    buf[e++] = av[i][j++];
                    buf[e] = '\0';
                }
                else
                {
                    if(ft_strchr(buf, av[i][j]))
                        j++;
                    else
                    {
                        buf[e++] = av[i][j++];
                        buf[e] = '\0';
                    }
                }
            }
            i++;
        }
        buf[e] = '\0';
    }
    printf("%s", buf);
}
