/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:07:17 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/07/10 17:54:16 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft/libft.h"
#include <math.h>
#include <stdio.h>
#define NB 37

typedef	struct		s_efct
{
	char			*name;
	char			*path;
	float			in_seconds;
	unsigned int	volume;
}					t_efct;

typedef	struct	s_snd
{
	t_efct		effect[NB];
}				t_snd;

int		ft_error(char *str);
int		init_path(t_efct *efct);
void	parsSongs(t_snd *snd);
void	init_name(t_snd *snd);
void	init_time(t_efct *efct, FILE *wavFd);
void	playSound(char *sound, int start, int vol);

#endif
