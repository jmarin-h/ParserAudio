/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:25:40 by jmarin-h          #+#    #+#             */
/*   Updated: 2016/03/12 20:36:05 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = NULL;
	if (!s)
		return (NULL);
	while (ft_isblank_extended(s[i]) == 1)
		i++;
	j = (ft_strlen(s));
	j--;
	while (ft_isblank_extended(s[j]) == 1)
		j--;
	j++;
	if (i >= j)
		str = ft_strdup("\0");
	else
		str = ft_strsub(s, i, (j - i));
	return (str);
}
