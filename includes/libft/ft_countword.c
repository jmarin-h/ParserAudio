/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 19:11:05 by jmarin-h          #+#    #+#             */
/*   Updated: 2016/11/30 22:34:33 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(const char *str, char c)
{
	int		i;
	int		j;
	int		ok;

	i = 0;
	j = 0;
	ok = 1;
	while (str[i])
	{
		if (str[i] != c && ok)
		{
			j++;
			ok = 0;
		}
		else if (str[i] == c)
			ok = 1;
		i++;
	}
	return (j);
}
