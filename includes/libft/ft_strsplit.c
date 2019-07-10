/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 23:30:38 by jmarin-h          #+#    #+#             */
/*   Updated: 2016/11/30 22:15:22 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ft_countword(s, c) + 1);
	if (!tab)
		return (NULL);
	while (j < ft_countword(s, c))
	{
		len = ft_lenword(s, c, &i);
		tab[j] = (char *)malloc(sizeof(char) * len);
		tab[j] = ft_strsub(s, i, len);
		i += len;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
