#include "unistd.h"
#include "stdarg.h"
#include "limits.h"
#include "stdlib.h"
#include "stdio.h"

void ft_putstr(char *str, int *size)
{
    int i = 0;
    if (!str)
    {
        *size = *size  + 6;
        write(1, "(null)", 6);
        return ;
    }
    while (str[i])
    {
        write(1, &str[i], 1);
        (*size)++;
        i++;
    }
}

void ft_putnbr(int num, int *size)
{
    char tmp;
    if (num == INT_MIN)
    {
        write (1, &"-2147483648", 11);
        return ;
    }
    else if (num > 9)
    {
        ft_putnbr(num / 10, size);
        ft_putnbr(num % 10, size);
        // num /= 10;
    }
    else if (num < 0)
    {
        write(1, "-", 1);
        ft_putnbr(num * -1, size);
    }
    else
    {
        tmp = num + 48;
        (*size)++;
        write(1, &tmp, 1);
    }
}

void ft_puthexa(unsigned int num, int *size)
{
    if (num >= 16)
    {
        ft_puthexa(num / 16, size);
    }
    (*size)++;
    write (1, &"0123456789abcdef"[num % 16], 1);
}

void deal_sp(const char *str, va_list list, int *i, int *size)
{
    if (str[0] == 's')
    {
        ft_putstr(va_arg(list, char *), size);
        (*i)++;
    }
    else if (str[0] == 'd')
    {
        ft_putnbr(va_arg(list, int), size);
        (*i)++;
    }
    else if (str[0] == 'x')
    {
        ft_puthexa(va_arg(list, unsigned int), size);
        (*i)++;
    }
    else
        (*i)++;
}

int ft_printf(const char *str, ...)
{
    va_list list;
    int     size;
    int     i;

    if (!str)
        return (0);
    va_start(list, str);
    i = 0;
    size = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            deal_sp(&str[i], list, &i, &size);
        }
        if (str[i] == '\0')
            break;
        write(1, &str[i], 1);
        size++;
        if (str[i])
            i++;
    }
    va_end(list);
    return (size);
}

// int main(void)
// {
//     printf("%d" , ft_printf("%e", -2147483648));
//     // printf("-%x-%x-%x-%x", 0, 0, 42, 42);
//     // printf(" REAL %d ", printf(" %s \n", "wiurwuyrhwrywuier"));
// }