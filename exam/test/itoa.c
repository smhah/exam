#include<stdio.h>
#include<stdlib.h>


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

void  ft_itoa(int n)
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
    printf("str is |%s|s", str);
}

int main()
{
    ft_itoa(0);
}
