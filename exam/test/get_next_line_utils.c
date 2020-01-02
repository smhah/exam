#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}

char *ft_strdup(char *str)
{
    int i;
    char *buf;

    i = 0;
    buf = malloc(ft_strlen(str) + 1);
    while(str[i])
    {
        buf[i] = str[i];
        i++;
    }
    buf[i] = '\0';
    return(buf);
}
char *ft_substr(char *str, int start, int len)
{
    char *buf;
    int i;

    i = 0;
    buf = malloc(len + 1);
    while(len-- && str[start])
        buf[i++] = str[start++];
    buf[i] = '\0';
    return(buf);
}

char *ft_strjoin(char *str1, char *str2)
{
    char *buff;
    int i;
    int j;

    i = 0;
    j = 0;
    buff = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
    while (str1[i])
    {
        buff[i] = str1[i];
        i++;
    }
    while(str2[j])
    {
        buff[i++] = str2[j++];
    }
    buff[i] = '\0';
    return(buff);
}

char  *ft_strchr(char *str, int a)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == a)
            return(&str[i]);
        i++;
    }
    return(0);
}
// int main ()
// {
//     char *s = "salahissparta";

//     s = ft_strchr(s, 'c');
//     printf("s is :|%s|\n", s);
// }