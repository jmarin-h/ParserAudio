/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:06:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/08/16 03:36:33 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser.h"

int		main(int ac, char **av)
{
	int		vol;
	t_snd	snd;

	vol = 0;
	snd = *(t_snd *)malloc(sizeof(t_snd));
	parserAudio(&snd);
	if(ac == 2)
		play_sound(&snd, av[1]);
	if(ac == 3 && ft_strcmp(av[2], "info") == 0)
		info_sound(&snd, av[1]);
	else if (ac == 3)
	{
		vol = ft_atoi(av[2]);
		vol_sound(vol);
		play_sound(&snd, av[1]);
	}
	return(0);
}
