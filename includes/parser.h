/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:07:17 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/08/28 12:30:40 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft/libft.h"
#include <math.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SOUNDS 39
#define VOLUME_MAX 8

typedef	struct		s_efct
{
	int				pid;
	char			*name;
	char			*path;
	float			in_seconds;
	unsigned int	ovl_size;
	unsigned int	volume;
}					t_efct;

typedef struct		s_chnl
{
	int				num_channels;
	int				channel;
	int				volume;
}					t_chnl;

typedef	struct		s_snd
{
	int				num_sound;
	t_efct			effect[SOUNDS];
}					t_snd;

int		volume(int vol);
int		ft_error(char *str);
int		init_pid(t_efct *efct);
int		init_path(t_efct *efct);
int		parserAudio(t_snd *snd);
int		init_name(t_snd *snd);
int		play(t_snd *snd, char *sound);
int		play_sound(t_snd *snd, char *sound, char *arg3);
int		info_sound(t_snd *snd, char *sound);
void		init_time(t_efct *efct, FILE *wavFd);

#endif
