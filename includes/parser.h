/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-h <jmarin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:07:17 by jmarin-h          #+#    #+#             */
/*   Updated: 2019/07/10 13:28:04 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft/libft.h"
#include <math.h>
#include <stdio.h>
//#include "sound.h"

typedef	struct		s_efct
{
	char			*name;
	char			*path;
	float			in_seconds;
	unsigned int	volume;
//	FILE			file;
}					t_efct;

typedef	struct	s_snd
{
	t_efct		*arrow_1;
	t_efct		*arrow_2;
	t_efct		*boomerang;
	t_efct		*explosion_1;
	t_efct		*explosion_2;
	t_efct		*fall;
	t_efct		*fall_window_1;
	t_efct		*fall_window_2;
	t_efct		*fireball;
	t_efct		*fire_serious;
	t_efct		*fire;
	t_efct		*grunt_monster_1;
	t_efct		*grunt_monster_2;
	t_efct		*gun_1;
	t_efct		*harpon;
	t_efct		*knife_fall;
	t_efct		*knife_throw;
	t_efct		*lasergun_1;
	t_efct		*lasergun_2;
	t_efct		*refill_gun;
	t_efct		*refill_long;
	t_efct		*refill_shotgun_1;
	t_efct		*refill_shotgun_2;
	t_efct		*shuriken_throw;
	t_efct		*silencieux;
	t_efct		*slap_1;
	t_efct		*smg_1;
	t_efct		*smg_2;
	t_efct		*smg_famas_1;
	t_efct		*smg_ww1_1;
	t_efct		*spear;
	t_efct		*sword_1;
	t_efct		*sword_2;
	t_efct		*sword_3;
	t_efct		*sword_4;
	t_efct		*trident;
	t_efct		*water_splash;
	t_efct		*whip_1;
	t_efct		*whip_2;
	t_efct		end;
}				t_snd;

int		ft_error(char *str);
int		init_path(t_efct *efct);
int		init_name(t_efct *efct);
void	parsSongs();
void	init_soundName(t_snd snd);
void	init_time(t_snd *snd, FILE *wavFd);
void	playSound(char *sound, int start, int end);

#endif
