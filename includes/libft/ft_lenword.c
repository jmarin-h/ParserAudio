/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:03:10 by jmarin-h          #+#    #+#             */
/*   Updated: 2016/03/12 20:35:34 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenword(const char *str, char c, int *i)
{
	int		len;

	len = 0;
	while (str[*i] == c)
		(*i)++;
	while (str[*i + len] && str[*i + len] != c)
		len++;
	return (len);
}
