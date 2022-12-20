#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

static unsigned int parse_int(long int n, char *base)
{
  ft_putnbr_base(n, base); 
  return (ft_intlen_base(n, ft_strlen(base)));
}

static unsigned int parse_string(char *str)
{
  if(!str)
  {
    ft_putstr_fd("(null)", 1);
    return (6);
  }
  ft_putstr_fd(str, 1);
  return(ft_strlen(str));
}

static unsigned int parse_pointer(unsigned long long n)
{
  if(!n)
  {
    ft_putstr_fd("(nil)",1);
    return (5);
  }
  ft_print_address_hex(n);
  return (15);
}

static unsigned int parse_ap(const char c, va_list ap)
{
  if (c == 'd' || c == 'i')
    return (parse_int(va_arg(ap, int), "0123456789"));
  else if (c == 'c')
    ft_putchar_fd(va_arg(ap, int), 1);
  else if (c == '%')
    ft_putchar_fd('%', 1);
  else if (c == 'u')
    return (parse_int(va_arg(ap, unsigned int), "0123456789"));
  else  if (c == 's')
    return (parse_string(va_arg(ap, char *)));
  else if (c == 'x')
    return (parse_int(va_arg(ap, int), "0123456789abcdef"));
  else if (c == 'X')
    return (parse_int(va_arg(ap, int), "0123456789ABCDEF"));
  else if (c == 'p')
    return (parse_pointer(va_arg(ap, unsigned long long)));
  return (1);
}


int ft_printf(const char* arg, ...)
{
  va_list ap;
  int len;
  int i;

  i = 0;
  len = 0;
  va_start(ap, arg);
  while (arg[i] != '\0') 
  {
    if (arg[i] == '%')
      len = parse_ap(arg[++i], ap);
    else 
      ft_putchar_fd(arg[i], 1);
    i++;
  }
  va_end(ap);
  return(len);
}
