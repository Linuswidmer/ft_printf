#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr_base(int nbr, char *base)
{
	int len;
	char print;

	len = ft_strlen(base);
	if( nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	if(nbr < len)
	{
		print = base[nbr % len];
		write(1, &print, 1);
	} 
	else 
	{
		ft_putnbr_base(nbr / len, base);
		print = base[nbr % len];
		write(1, &print, 1);
	}
}
