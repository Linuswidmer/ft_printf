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
    ft_putnbr_fd(va_arg(ap, int), 1); // does not work yet
  else  if (c == 's')
    ft_putstr_fd(va_arg(ap, char *), 1);
  else if (c == 'x')
    ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
  else if (c == 'X')
    ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
  else if (c == 'p')
    {
    ft_putstr_fd("0x", 1);
    ft_print_address_hex(va_arg(ap, unsigned long long));
    }
  else
    return ;
}

static unsigned int parse_len(const char c, va_list ap_copy)
{
  if (c == 'd' || c == 'i')
    return(ft_intlen(va_arg(ap_copy, int)));
  else if (c == 'c')
    return (1);
  else if (c == '%')
    return (1);
  else if (c == 'u')
    return(ft_intlen(va_arg(ap_copy, int)));
  else  if (c == 's')
    return (ft_strlen(va_arg(ap_copy, char *)));
  else if (c == 'x')
    return (ft_hexlen(va_arg(ap_copy, int)));
  else if (c == 'X')
    return (ft_hexlen(va_arg(ap_copy, int)));
  else if (c == 'p')
    return (15);
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

// int main(void)
// {
//  char str[] = "%d";
  // void *ptr;
  // int i;
  // unsigned int len;
  //
  // i = 42;
  // ptr = &i;
  // ft_printf("%c some text %s %%some more %i hex: %x", 'c', "hello world", 123, -123456);
  // len = ft_printf("%s%xfour", "helloxx", 0);
  // printf("\n");
  // printf("%i\n", len);
  // printf("%p\n", ptr);
  // printf("%li\n", sizeof(ptr));
  // ft_prit_address_hex(ptr);
  // printf("%i\n", ft_printf("%p", ptr));
  // printf("%i\n", printf("\n%p", ptr));
//   printf(str, 22);
// }

