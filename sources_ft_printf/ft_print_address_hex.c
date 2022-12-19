#include "libft.h"
#include "ft_printf.h"

void ft_print_address_hex(unsigned long long address)
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
		ft_print_address_hex(address / 16);
		print = base[address % 16];
		write(1, &print, 1);
	}
}
