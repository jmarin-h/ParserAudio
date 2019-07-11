/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:15:01 by jmarin-h          #+#    #+#             */
/*   Updated: 2016/02/12 14:37:06 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (ptr[i] != '\0')
		i++;
	while (ptr[i] != c)
	{
		i--;
		if (ptr[i] == c)
			return (&ptr[i]);
		if (ptr[i] == ptr[0])
			return (NULL);
	}
	if (c == 0)
		return (ptr + i);
	return (NULL);
}
