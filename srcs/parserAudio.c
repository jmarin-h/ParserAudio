#include "../includes/parser.h"

void	vol_sound(int vol)
{
	int	i;
	int	volume;

	i = 0;
	// amixer sset 'Master' 50%
}

void	cut_sound(char *sound, float start, float end)
{
}

void	playSound(t_snd *snd, char *sound, float start, float end, unsigned int vol)
{
	int		i;
	int		ok;
	char	*str;

	i = 0;
	ok = 0;
	while(i <= SOUNDS)
	{
		if(ft_strcmp(sound, snd->effect[i].name) == 0)
		{
			ok = 1;
			if(start != 0)
				cut_sound(snd->effect[i].path, start, end);
			if(vol != 128)
				vol_sound(vol);
		//	str = ft_strjoin("afplay ", snd->effect[i].path);
			str = ft_strjoin("mplayer ", snd->effect[i].path);
			str = ft_strjoin(str, ".wav&");
			system(str);
		}
		if(i == SOUNDS && ok == 0)
			ft_putendl("Sound not found.");
		i++;
	}
}

int		ft_error(char *str)
{
	if(str)
		ft_putendl(str);
	return(1);
}

int		parserAudio(t_snd *snd)
{
	int		i;
	int		error;

	error = 0;
	i = 0;
	init_name(snd);
	while(i <= (SOUNDS - 1) && error == 0)
	{
		error = init_path(&snd->effect[i]);
		i++;
	}
	return(0);
}
