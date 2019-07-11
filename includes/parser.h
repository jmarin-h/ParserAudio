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
#define SOUNDS 38

typedef	struct		s_efct
{
	char			*name;
	char			*path;
	float			in_seconds;
	unsigned int	volume;
}					t_efct;

typedef	struct	s_snd
{
	t_efct		effect[SOUNDS];
}				t_snd;

int		ft_error(char *str);
int		init_path(t_efct *efct);
void	parsSongs(t_snd *snd);
void	init_name(t_snd *snd);
void	init_time(t_efct *efct, FILE *wavFd);
void	cut_sound(char *sound, float start, float end);
void	playSound(t_snd *snd, char *sound, float start, float end, unsigned int vol);

#endif
