/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:06:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/08/14 20:17:46 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser.h"

int		main(int ac, char **av)
{
	int		fd;
	t_snd	snd;

	snd = *(t_snd *)malloc(sizeof(t_snd));
	parserAudio(&snd);
	if(ac >= 2)
	{
		if(ac == 2)
			playSound(&snd, av[1], 0, 0, VOLUME_MAX);
		if(ac == 3)
			get_soundInfo(&snd, av[1]);
	}
	return(0);
}
