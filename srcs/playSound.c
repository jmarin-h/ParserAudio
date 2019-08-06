/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:06:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/08/06 17:13:58 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		ft_error(char *str)
{
	if(str)
		ft_putendl(str);
	return(0);
}

void	vol_sound(char *sound, int vol)
{
	int	i;
	int	volume;

	i = 0;
	volume = vol;
	sound = "test";
}

void	cut_sound(char *sound, float start, float end)
{
	sound = "test";
	start = end = 0;
}
/*
void	playSound(t_snd *snd, char *sound, float start, float end, unsigned int vol)
{
	int		i;
	int		ok;
	char	*str;

	i = 0;
	ok = 0;
	while(i <= snd->nb_sound)
	{
		if(ft_strcmp(snd->effect[i].name, sound) == 0)
		{
			ok = 1;
			if(start != 0)
				cut_sound(snd->effect[i].path, start, end);
			if(vol != 128)
				vol_sound(snd->effect[i].path, vol);
			str = ft_strjoin("afplay ", snd->effect[i].path);
	//		str = ft_strjoin("mplayer ", snd->effect[i].path);
			str = ft_strjoin(str, "&");
			printf("sound path = %s\n", str);
			system(str);
			break;
		}
		if(i == snd->nb_sound && ok == 0)
			ft_putendl("Sound not found.");
		i++;
	}
}
*/
void	playSound(t_snd *snd, char *sound, float start, float end, unsigned int vol)
{
	int		i;
	int		ok;
	char	*str;

	i = 0;
	ok = 0;
	while(i <= snd->nb_sound)
	{
		if(ft_strcmp(snd->effect.name, sound) == 0)
		{
			ok = 1;
			if(start != 0)
				cut_sound(snd->effect.path, start, end);
			if(vol != 128)
				vol_sound(snd->effect.path, vol);
			str = ft_strjoin("afplay ", snd->effect.path);
		//	str = ft_strjoin("mplayer ", snd->effect.path);
			str = ft_strjoin(str, "&");
			printf("sound path = %s\n", str);
			system(str);
			break;
		}
		if(i == snd->nb_sound && ok == 0)
			ft_putendl("Sound not found.");
		i++;
	}
}
