#include "ft_printf.h"

unsigned int	ft_intlen(int n)
{
	unsigned int	i;

  i = 0;
  if(n < 0)
  {
    i++;
    n = n * -1;
  }
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i + 1);
}
