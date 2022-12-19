#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
unsigned int ft_intlen(int n);
void ft_putnbr_base(int nbr, char *base);
unsigned int ft_hexlen(int nbr);
void ft_print_address_hex(unsigned long long address);
# endif
