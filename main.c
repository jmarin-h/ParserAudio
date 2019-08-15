/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:06:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/08/16 01:28:50 by jmarin-h         ###   ########.fr       */
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
		playSound(&snd, av[1], 2);
	if(ac == 3 && ft_strcmp(av[2], "info") == 0)
		get_soundInfo(&snd, av[1]);
	else if (ac == 3)
	{
		vol = ft_atoi(av[2]);
		playSound(&snd, av[1], vol);
	}
	return(0);
}
