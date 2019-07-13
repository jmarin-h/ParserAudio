/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:06:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/07/13 15:46:13 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser.h"

void	vol_sound(char *sound, int vol)
{
	int	i;
	int	volume;

	i = 0;
}

void	cut_sound(char *sound, float start, float end)
{
}

void	playSound(t_snd *snd, char *sound, float start, float end, unsigned int vol)
{
	int		i;
	int		ok;
	char	*str;

	i = 0;
	ok = 0;
	while(i <= SOUNDS)
	{
		if(ft_strcmp(sound, snd->effect[i].name) == 0)
		{
			ok = 1;
			if(start != 0)
				cut_sound(snd->effect[i].path, start, end);
			if(vol != 128)
				vol_sound(snd->effect[i].path, vol);
			str = ft_strjoin("afplay ", snd->effect[i].path);
			str = ft_strjoin(str, ".wav&");
			system(str);
		}
		if(i == SOUNDS && ok == 0)
			ft_putendl("Sound not found.");
		i++;
	}
}

int		ft_error(char *str)
{
	if(str)
		ft_putendl(str);
	return(1);
}

void	parsSongs(t_snd *snd)
{
	int		i;
	int		error;

	error = 0;
	i = 0;
	ft_putendl("Init parsSongs...");
	init_name(snd);
	while(i <= (SOUNDS - 1) && error == 0)
	{
		error = init_path(&snd->effect[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	t_snd	snd;

	snd = *(t_snd *)malloc(sizeof(t_snd));
	if(!(snd.invtr = open("sound.txt", O_RDONLY)))
		return(ft_error("Error open file."));
	parsSongs(&snd);
	if(ac == 2)
		playSound(&snd, av[1], 0, 0, VOLUME_MAX);
	close(snd.invtr);
	return(0);
}
