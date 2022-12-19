#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int ft_printf(const char* arg, ...);

int main(int argc, char **argv)
{
  (void)argc;
  int arr[] = {-2147483648, -12345, -9, -0, 0, 4, 238462, 2147483647}; 

  printf("my ft_printf:\n");
  ft_printf("%i", arr[ft_atoi(argv[1])]); 
  printf("orignal printf:");
  printf("%i\n", arr[ft_atoi(argv[1])]);
}
