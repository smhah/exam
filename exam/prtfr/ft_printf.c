#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int i;
    int signe;
    int resultat;

    resultat = 0;
    signe = 1;
    i = 0;
    while(str[i] && ((str[i] >= 8 && str[i] <= 13) || str[i] == ' '))
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            signe = -1;
        i++;
    }
    while(str[i] <= '9' && str[i] >= '0')
    {
        resultat = resultat * 10 + str[i] - 48;
        i++;
    }
    return(resultat * signe);
}

char *ft_itoa1(int n, int *i, char **str)
{
    if (n < 10 && n >=0)
    {
        (*str)[*i] = n + 48;
    }
    else
    {
        ft_itoa1(n / 10, i, str);
        *i = *i + 1;
        ft_itoa1(n % 10, i, str);
    }
    return(*str);
}

char    *ft_itoa(int n)
{
    int d;
    int c;
    char *str;
    int i;

    i = 0;
    d = n;
    c = 0;
    while (d > 0)
    {
        d = d / 10;
        c++;
    }
    if (n == 0)
    {
        str = malloc(2);
        str[0] = '0';
        str[1] = '\0';
    }
    else if (n < 0)
    {
        str = malloc(c + 2);
        str[i] = '-';
        i++;
        n = n * (-1);
    }
    else
        str = malloc(c + 1);
    ft_itoa1(n, &i, &str);
    str[i + 1] = '\0';
    return(str);
}
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}

// char *ft_strjoin(char *s1, char *s2)
// {
//     int i;
//     int j;
//     char *buf;

//     i = -1;
//     while(s1[++i])
//         buf[i] = s1[i];
//     j = 0;
//     while(s2[j])
//         buf[i++] = s2[j++];
//     buf[i] = '\0';
//     return (buf);
// }
void ft_active(char *tab, char *flag)
{
    int i;
    int j;
    int len;

    len = ft_atoi(&flag[1]) - ft_strlen(tab);
    if(len <= 0)
        return ;
    while(len--)
        printf("%c", '0');
    printf("%s", tab);
}
int ft_printf(char *arg, ...)
{
    char *tab;
    int i;
    va_list n;
    int e;
    char *flag;
    int f;

    f = 0;
    i = 0;
    e = 0;
    flag = NULL;
    va_start(n, arg);
    while(arg[i])
    {
        while(arg[i] && arg[i] != '%')
            write(1, &arg[i++], 1);
        if (!arg[i++])
            break;
        printf("|%c|", arg[i]);
        while(arg[i] && (arg[i] != 's' || arg[i] != 'd' || arg[i] != 'x'))
        {
            if (flag == NULL)
                flag = malloc(ft_strlen(arg));
            flag[f++] = arg[i++];
        }
        printf("|%c|", arg[i]);
        if(arg[i] == 'd')
            tab = ft_itoa(va_arg(n, int));
        printf("%s", tab);
        if (flag)
            ft_active(tab,flag);
        else
            printf("%s", tab);
    }
    return (1);
}

int main()
{
    ft_printf("s%ds", 128);
}