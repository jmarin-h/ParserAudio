#include "libft.h"

int	ft_intlen(int nb)
{
	int cp;

	cp = 0;
	if(nb == 0)
		return(1);
	if (nb < 0)
	{
		nb = -nb;
		cp++;
	}
	while(nb > 0)
	{
		nb /= 10;
		cp++;
	}
	return (cp);
}
