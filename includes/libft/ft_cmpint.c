#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	write(1, str, i);
}

int     ft_peer(int nb)
{
	if ((nb % 2) != 0)
		return (0);
	else
		return (1);
}

int		ft_intlen(int	nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while(nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int		ft_bool(int nb)
{
	if (nb == 1)
		return (0);
	if (nb == 0)
		return (1);
	return(0);
}

char	*ft_cmpint(int nb)
{
	int		i;
	int		start;
	int		tab;
	int		len;

	i = 0;
	len = ft_intlen(nb);
	while(nb > 0)
	{
			
	}
	tab[i] = '\0';
	return (0);
}

int		main(void)
{
	ft_putstr(ft_cmpint(4));
}
