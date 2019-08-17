/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:06:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/08/17 04:28:43 by jmarin-h         ###   ########.fr       */
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
		printf("je suis la\n");
		sleep(ft_atoi(av[3]));
		stop_sound(&snd, av[1]);
	}
	else if (ac == 3)
	{
		vol_sound(ft_atoi(av[2]));
		play_sound(&snd, av[1]);
	}
	return(0);
}
