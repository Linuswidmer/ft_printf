#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int ft_printf(const char* arg, ...);

int main(int argc, char **argv)
{
  (void)argc;
  int int_test[] = {-2147483648, -12345, -9, -0, 0, 4, 238462, 2147483647}; 
  int u_int_test[] = {-2147483648, -12345, -9, -0, 0, 4, 238462, 2147483647, 4294967295}; 
  // const char *str_test[4]; 
 const char *str_test[] = {"hello", "", "\n", "\200 \0"};

  // char str_test[0] = "hello";
  // char str_test[1] = "\n";
  // char str_test[2] = "";
  // char str_test[3] = "\200 \0";


  if (int_test[ft_atoi(argv[1])])
  {
    printf("INT TEST:\n");
    printf("my ft_printf:\n");
    ft_printf("%i", int_test[ft_atoi(argv[1])]); 
    printf("\norignal printf:");
    printf("\n%i\n", int_test[ft_atoi(argv[1])]);
    printf("\n");
  }
  if (u_int_test[ft_atoi(argv[1])])
  {
    printf("UNSIGNED INT TEST:\n");
    printf("my ft_printf:\n");
    ft_printf("%u", u_int_test[ft_atoi(argv[1])]); 
    printf("\norignal printf:");
    printf("\n%u\n", u_int_test[ft_atoi(argv[1])]);
    printf("\n");
  }
  if (str_test[ft_atoi(argv[1])])
  {
    printf("STRING TEST:\n");
    printf("my ft_printf:\n");
    ft_printf("%s", str_test[ft_atoi(argv[1])]); 
    printf("\norignal printf:");
    printf("\n%s\n", str_test[ft_atoi(argv[1])]);
    printf("\n");
  }
}
