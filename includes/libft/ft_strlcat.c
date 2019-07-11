/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 05:27:27 by jmarin-h          #+#    #+#             */
/*   Updated: 2015/10/27 19:30:36 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t s1_end;

	i = 0;
	while (dst[i] && (size_t)i < dstsize)
		i++;
	s1_end = i;
	while (src[i - s1_end] && (size_t)i < dstsize - 1)
	{
		dst[i] = src[i - s1_end];
		i++;
	}
	if ((size_t)s1_end < dstsize)
		dst[i] = '\0';
	return (s1_end + ft_strlen(src));
}
