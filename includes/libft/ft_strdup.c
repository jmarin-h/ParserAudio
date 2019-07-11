/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 03:52:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2016/02/12 14:35:26 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*cp;

	i = ft_strlen(s);
	if ((cp = malloc(sizeof(*s) * (i + 1))) == NULL)
		return (NULL);
	while (i >= 0)
	{
		cp[i] = s[i];
		i--;
	}
	return (cp);
}
