#include "ft_printf.h"
#include <stdio.h>

int main()
{
  int i;
  void *ptr;
  char *str;

  str = NULL;

  i = -42;
  ptr = NULL;
  printf("%i\n", ft_printf("%s\n", "Hello World"));
  ft_printf("%u\n", -123456);
  printf("%u\n", -123456);
  printf("%i\n", ft_printf("%i\n", i));
  printf("%i\n", ft_printf("%c\n", 'c'));
  printf("%i\n", ft_printf("%%\n"));
  printf("%i\n", ft_printf("%x\n", 15));
  printf("%i\n", ft_printf("%X\n", 15));
  printf("%i\n", ft_printf("%p\n", ptr));
  printf("%i\n", ft_printf("%s\n", str));
  printf("\n");
  printf("\n");
  printf("%i\n", ft_printf("%p\n", &i));
  printf("%i\n", printf("%p\n", &i));
}
