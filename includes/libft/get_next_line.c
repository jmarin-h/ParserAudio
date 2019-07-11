/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:07:39 by jmarin-h          #+#    #+#             */
/*   Updated: 2017/01/05 04:18:21 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static char	*s;
	char		*t[2];
	int			i;

	if ((!line) || (!(t[0] = malloc(sizeof(char) * (BUFF_SIZE + 1))))
			|| (!s && !(s = malloc(sizeof(char)))))
		return (-1);
	while (!ft_strchr(s, '\n'))
	{
		if ((i = read(fd, t[0], BUFF_SIZE)) == 0)
			break ;
		if (i == -1)
			return (-1);
		t[0][i] = '\0';
		t[1] = ft_strjoin(s, t[0]);
		ft_strdel(&s);
		s = t[1];
	}
	if (!(*line = ft_strsub(s, 0, ft_strnlen(s, '\n'))))
		return (-1);
	ft_strdel(&t[0]);
	if ((i = (ft_strnlen(s, '\n') + 1)) && ft_strlen(s) == 0)
		return (0);
	s = ft_strsub(s, i, ft_strlen(&s[i]));
	return (1);
}
