/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 23:06:44 by jmarin-h          #+#    #+#             */
/*   Updated: 2016/10/05 19:04:42 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)src;
	s2 = (char *)dest;
	while (i < n && s1[i] != c)
	{
		s2[i] = s1[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
		s2[i] = s1[i];
	return ((void *)s2 + (i + 1));
}
