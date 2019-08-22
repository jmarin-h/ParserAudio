/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:06:14 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/08/22 03:37:12 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser.h"

int		main(int ac, char **av, char **env)
{
	t_snd	snd;

	snd = *(t_snd *)malloc(sizeof(t_snd));
	parserAudio(&snd);
	if(ac == 3)
		play_sound(&snd, av[1], av[2]);
	return(0);
}
