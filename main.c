/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:06:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/08/19 22:02:09 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser.h"

int		main(int ac, char **av, char **env)
{
	t_snd	snd;

	snd = *(t_snd *)malloc(sizeof(t_snd));
	parserAudio(&snd);
	if(ac == 2)
		play_sound(&snd, av[1]);
	else if(ac == 3 && ft_strcmp(av[2], "info") == 0)
		info_sound(&snd, av[1]);
	else if(ac == 4 && ft_strcmp(av[2], "stop") == 0)
	{
		play_sound(&snd, av[1]);
		sleep(ft_atoi(av[3]));
		stop_sound(&snd, av[1]);
	}
	else if (ac == 3)
	{
		vol_sound(ft_atoi(av[2]));
		// modif process vol_sound
		// join process vol_s play_s
	//	play_sound(&snd, av[1]);
	}
	return(0);
}
