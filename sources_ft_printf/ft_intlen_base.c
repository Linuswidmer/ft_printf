#include "ft_printf.h"

unsigned int	ft_intlen_base(long int n, unsigned int baselen)
{
	unsigned int	i;

  i = 0;
  if(n < 0)
  {
    i++;
    n = n * -1;
  }
	while (n > (baselen - 1))
	{
		i++;
		n = n / baselen;
	}
	return (i + 1);
}
