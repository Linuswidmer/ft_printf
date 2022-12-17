#include "../includes_ft_printf/ft_printf.h"
#include <stdio.h>
#include "../libft/sources_libft/libft.h"

static unsigned int parse(char c, va_list ap)
{
  if (c == 'd' || c == 'i')
  {
    ft_putnbr_fd(va_arg(ap, int), 1);
    return (ft_intlen(va_arg(ap, int)));
  }
  else if (c == 'c')
    ft_putchar_fd(va_arg(ap, int), 1);
  else if (c == '%')
    ft_putchar_fd('%', 1);
  else if (c == 'u')
    ft_putnbr_fd(va_arg(ap, int), 1); // does not work yet
  else  if (c == 's')
  {
    printf("%s\n", va_arg(ap, char *));
    ft_putstr_fd(va_arg(ap, char *), 1);
    // return (ft_strlen(va_arg(ap, char *)));
  }
  return (1);
}

int ft_printf(const char* arg, ...)
{
  va_list ap;
  va_start(ap, arg); // arg is last var name before ellipse
  int i;
  int len;

  i = 0;
  len = 0;
  while (arg[i] != '\0') {
  
    if (arg[i] == '%')
    {
      i++;
      len = len + parse(arg[i], ap);
    }
    else 
      ft_putchar_fd(arg[i], 1);
    i++;
    }
  va_end(ap);
  //i have to change the return value still
  return(len + i);
}

int main(void)
{
  // int len;

    ft_printf("%%\nnormal text \n digit: %d \n character: %c\n unsigned int: %u\n string: %s", -312, 48, 124, "Hello world");
    // len = ft_printf("\nsecond test%d", 123);
    // printf("%i\n", len);
}

