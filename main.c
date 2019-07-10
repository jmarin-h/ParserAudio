/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:06:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/07/04 18:43:33 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser.h"

void	playSound(char	*sound, int start, int end)
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

int		init_name(t_snd snd.efct)
{
		int		i;
		char	**tab;

		i = 0;
		if(!(snd.efct.name = malloc(sizeof(char) * ft_strlen(snd.efct.name))))
			return(ft_error("Error malloc filename"));
		tab = ft_strsplit(snd.effect.name, '/');
		while(tab[i])
			i++;
		snd.efct.mane = tab[i - 1];
		i = 0;
		while(tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		return(0);
}

void	parsSongs(t_snd snd)
{
	int		error;

	error = 0;
	ft_putendl("Init parsSongs...");
	snd = malloc(sizeof(t_snd));
	init_soundName(snd);
	while(snd.efct != NULL && error == 0)
	{
		error = init_name(snd.efct);
		error = init_path(snd);
		snd.efct++;
	}
}

int		main(int ac, char **av)
{
	t_snd	snd;

	parsSongs(snd);
	if(ac == 2)
	{
		playSound(av[1], 0, 0);
	}
	return(0);
}
