/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:45:19 by jmarin-h          #+#    #+#             */
/*   Updated: 2016/03/11 21:59:52 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	len;
	char	*s1;
	char	*s2;

	s1 = (char *)src;
	s2 = (char *)dest;
	i = 0;
	while (i < n)
	{
		if (s2 > s1)
			len = n - i - 1;
		else
			len = i;
		s2[len] = s1[len];
		i++;
	}
	return ((void *)s2);
}
