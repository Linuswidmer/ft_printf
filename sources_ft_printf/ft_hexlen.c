#include "libft.h"
#include "ft_printf.h"

unsigned int	ft_hexlen(int nbr)
{
	int len;

  len = 0;
	if( nbr < 0)
	{
		len ++;
		nbr = nbr * -1;
	}
  while (nbr >= 16)
  {
    nbr = nbr / 16;
    len ++;
  }
  return (len + 1);
}
