/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 11:22:56 by jmarin-h          #+#    #+#             */
/*   Updated: 2016/10/05 15:51:40 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((n == 0) || (!s1 && !s2))
		return (1);
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && i < n)
	{
		i++;
		if ((s1[i] && s2[i]) == '\0' || (i == n))
			return (1);
	}
	return (0);
}
