/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:07:17 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/08/14 20:17:21 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft/libft.h"
#include <math.h>
#include <stdio.h>
#define SOUNDS 38
#define VOLUME_MAX 128

typedef	struct		s_efct
{
	char			*name;
	char			*path;
	float				in_seconds;
	unsigned int	ovl_size;
	unsigned int	volume;
}					t_efct;

typedef struct		s_chnl
{
	int				num_channels;
	int				channel;
	int				volume;
}					t_chnl;

typedef	struct	s_snd
{
	int			num_sound;
	t_efct		effect[SOUNDS];
}				t_snd;

int		ft_error(char *str);
int		init_path(t_efct *efct);
int		parserAudio(t_snd *snd);
int		init_name(t_snd *snd);
void	get_soundInfo(t_snd *snd, char *sound);
void	init_time(t_efct *efct, FILE *wavFd);
void	cut_sound(char *sound, float start, float end);
void	playSound(t_snd *snd, char *sound, float start, float end, unsigned int vol);

#endif
