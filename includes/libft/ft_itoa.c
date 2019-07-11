#include "libft.h"

char	*ft_itoa(int nb)
{
	int 	len;
	char	*str;

	len = ft_intlen(nb);
	if(nb == INT_MIN)
		return ("-2147483648");
	if(!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	str[len] = '\0';
	while(nb > 0)
	{
		len--;
		str[len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (str);
}
