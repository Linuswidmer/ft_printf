#include "libft.h"
#include "ft_printf.h"

static void print_address(unsigned long long address)
{

	char print;
  char base[16] = "0123456789abcdef";
	if(address < 16)
	{
		print = base[address % 16];
		write(1, &print, 1);
	} 
	else 
	{
		print_address(address / 16);
		print = base[address % 16];
		write(1, &print, 1);
	}
}
void ft_print_address_hex(unsigned long long address)
{
  if(address)
  {
    ft_putstr_fd("0x", 1);
    print_address(address);
  }
  else
    ft_putstr_fd("(nil)", 1);
}
