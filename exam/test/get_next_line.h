#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_next_line(char **str, int fd);
int ft_strlen(char *str);
char *ft_strdup(char *str);
char *ft_substr(char *str, int start, int len);
char *ft_strjoin(char *str1, char *str2);
char  *ft_strchr(char *str, int a);