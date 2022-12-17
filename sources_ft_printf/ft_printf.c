#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"


static void ft_print_address_hex(const void *ptr)
{
  long int value;
  value = (long int)&ptr;

  printf("%li\n", value);
  printf("%li\n", ((long int)ptr));

  printf("\n");
  ft_putchar_fd(*(unsigned char*)&value ,1);
  // while (i < 8)
  // {
  //   value = (unsigned char)(ptr + i);
  //   printf("%i\n", value);
  //   num = (char)ptr;
  //   printf("%hhn\n", (unsigned char*)ptr);
  //   i++;
  // }
  // printf("%p\n", ptr);
}

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
    ft_print_address_hex(va_arg(ap, void *));
  else
    return ;
}

int ft_printf(const char* arg, ...)
{
  va_list ap;
  int i;
  int len;

  //va_copy

  va_start(ap, arg); // arg is last var name before ellipse
  i = 0;
  len = 0;
  while (arg[i] != '\0') 
  {
    if (arg[i] == '%')
      parse_ap(arg[++i], ap);
    else 
      ft_putchar_fd(arg[i], 1);
    i++;
  }
  va_end(ap);
  return(len + i);
}

int main(void)
{
  void *ptr;
  int i;

  i = 42;
  ptr = &i;
  ft_printf("%c some text %s %%some more %i hex: %x", 'c', "hello world", 123, -123456);
  printf("\n");
  printf("%p\n", ptr);
  printf("%li\n", sizeof(ptr));
  ft_print_address_hex(ptr);
}

