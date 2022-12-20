#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

static void parse_ap(const char c, va_list ap)
{
  if (c == 'd' || c == 'i')
    ft_putnbr_fd(va_arg(ap, int), 1);
  else if (c == 'c')
    ft_putchar_fd(va_arg(ap, int), 1);
  else if (c == '%')
    ft_putchar_fd('%', 1);
  else if (c == 'u')
    ft_putnbr_fd(va_arg(ap, unsigned int), 1);
  else  if (c == 's')
    ft_putstr_fd(va_arg(ap, char *), 1);
  else if (c == 'x')
    ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
  else if (c == 'X')
    ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
  else if (c == 'p')
    ft_print_address_hex(va_arg(ap, unsigned long long));
  else
    return ;
}

static unsigned int parse_len(const char c, va_list ap_copy)
{
  if (c == 'd' || c == 'i')
    return(ft_intlen(va_arg(ap_copy, int)));
  else if (c == 'c' || c == '%')
    return (1);
  else if (c == 'u')
    return(ft_intlen(va_arg(ap_copy, unsigned int)));
  else  if (c == 's')
    return (ft_strlen(va_arg(ap_copy, char *)));
  else if (c == 'x')
    return (ft_hexlen(va_arg(ap_copy, int)));
  else if (c == 'X')
    return (ft_hexlen(va_arg(ap_copy, int)));
  else if (c == 'p')
      if(va_arg(ap_copy, unsigned long long))
        return (15);
      else
        return(5);
  else
    return (0);
}


static unsigned int parse_string(const char *arg, va_list ap, va_list ap_copy)
{
  int i;
  int len;

  len = 0;
  i = 0;
  while (arg[i] != '\0') 
  {
    if (arg[i] == '%')
      parse_ap(arg[++i], ap);
    else 
      ft_putchar_fd(arg[i], 1);
    i++;
  }
  i = 0;
  while (arg[i] != '\0') 
  {
    if (arg[i] == '%')
      len = len + parse_len(arg[++i], ap_copy) - 2;
    i++;
  }
  return (len + i);
}

int ft_printf(const char* arg, ...)
{
  va_list ap;
  va_list ap_copy;
  int len;

  va_start(ap, arg);
  va_copy(ap_copy, ap);// arg is last var name before ellipse
  len = parse_string(arg, ap, ap_copy);
  va_end(ap);
  va_end(ap_copy);
  return(len);
}

// int main()
// {
//   int i;
//   void *ptr;
//   // char *str;
//
//   i = 42;
//   ptr = NULL;
//   // str = NULL;
//   printf("%p\n", &i);
//   ft_printf("%p", &i);
//   printf("\n");
//   printf("%p\n", ptr);
//   ft_printf("%p", ptr);
//
//   // printf("%i\n", 1283623847283623427);
//
//   // printf("\n%s\n", str);
//   // ft_printf("%s", str);
// }
