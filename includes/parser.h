/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:07:17 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/08/05 17:59:11 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft/libft.h"
#include <math.h>
#include <stdio.h>
#define VOLUME_MAX 128

typedef	struct		s_efct
{
	char			*name;
	char			*path;
	float			in_seconds;
	unsigned int	ovl_size;
	struct t_efct	*next;
}					t_efct;

typedef struct		s_chnl
{
	int				num_channels;
	int				channel;
	int				volume;
}					t_chnl;

typedef	struct		s_snd
{
	int				invtr;
	int				nb_sound;
	t_efct			effect[40];
}					t_snd;

int		ft_error(char *str);
int		init_path(t_efct *efct);
int		init_name(t_snd *snd);
int		parserAudio(t_snd *snd);
void	init_time(t_efct *efct, FILE *wavFd);
void	get_SoundInfo(t_snd *snd, char *sound);
void	cut_sound(char *sound, float start, float end);
void	playSound(t_snd *snd, char *sound, float start, float end, unsigned int vol);

#endif
