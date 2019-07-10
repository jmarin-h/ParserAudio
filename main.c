/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:06:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/07/10 17:54:19 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser.h"

void	playSound(char	*sound, int start, int vol)
{
	if(start == 0)
	{
		system(sound);
		//system("afplay ./includes/sound/sound.mp3&");
	}
	else
	{
//		cut_sound(sound, start, end);
		system(sound);
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
	while(i <= NB && error == 0)
	{
		error = init_path(&snd->effect[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_snd	snd;

	snd = *(t_snd *)malloc(sizeof(t_snd));
	parsSongs(&snd);
	if(ac == 2)
	{
		playSound(av[1], 0, 0);
	}
	return(0);
}
