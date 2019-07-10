/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:06:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/07/10 17:35:25 by jmarin-h         ###   ########.fr       */
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

int		init_name(t_efct *efct)
{
		int		i;
		char	**tab;

		i = 0;
		if(!(efct->name = malloc(sizeof(char) * ft_strlen(efct->name))))
			return(ft_error("Error malloc filename"));
		tab = ft_strsplit(efct->name, '/');
		while(tab[i])
			i++;
		efct->name = tab[i - 1];
		i = 0;
		while(tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		return(0);
}

void	parsSongs(t_snd *snd)
{
	int		i;
	int		error;

	error = 0;
	i = 0;
	ft_putendl("Init parsSongs...");
	init_soundName(snd);
	while(i < NB && error == 0)
	{
		error = init_path(&snd->effect[i]);
//		error = init_name(&snd->effect[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_snd	snd;

	snd = *(t_snd *)malloc(sizeof(t_snd));
//	snd.effect[NB] = NULL;
	parsSongs(&snd);
	if(ac == 2)
	{
		playSound(av[1], 0, 0);
	}
	return(0);
}
