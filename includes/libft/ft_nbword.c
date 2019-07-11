/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbword.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:21:38 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/06/18 16:29:41 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbword(char *s)
{
	int	i;
	int	nbword;

	i = 0;
	nbword = 0;
	while(s[i])
	{
		while(ft_isblank(s[i]) == 1)
			i++;
		if(ft_isblank(s[i]) == 0)
		{
			nbword++;
			while(ft_isblank(s[i]) == 0)
				i++;
		}
	}
		if(ft_isblank(s[ft_strlen(s) - 1]) == 1)
			nbword--;
		return (nbword);
}
