/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 03:26:06 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/08/16 00:06:03 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	negatif;
	int	nb;

	i = 0;
	negatif = 0;
	nb = 0;
	while (ft_isblank(nptr[i]))
		i++;
	if (nptr[i] == '-')
		negatif = 1;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
		i++;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		nb = nb * 10;
		nb += ((int)nptr[i] - '0');
		i++;
	}
	if (negatif)
		return (-nb);
	else
		return (nb);
}
