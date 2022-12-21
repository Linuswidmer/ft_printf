#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
unsigned int ft_intlen_base(long int , unsigned int base);
void ft_putnbr_base(long int nbr, char *base);
unsigned int ft_hexlen(int nbr);
unsigned int ft_print_address_hex(unsigned long long address);
int ft_printf(const char *arg, ...);
# endif
