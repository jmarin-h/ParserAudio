#include "../includes/parser.h"

int		ft_error(char *str)
{
	if(str)
		ft_putendl(str);
	return(1);
}

int		playSound(t_snd *snd, char *sound, int vol)
{
	int		i;
	int		ok;
	char	*str;

	i = 0;
	ok = 0;
	while(i < SOUNDS)
	{
		if(ft_strcmp(sound, snd->effect[i].name) == 0)
		{
			ok = 1;
//			if(vol >= 0 && vol <= 100)
			if(vol > 0 && vol <= 8)
				vol_sound(vol);
			else
				return(ft_error("Set volume from 1 to 8."));
//				return(ft_error("Set volume from 1 to 100."));
			str = ft_strjoin("afplay ", snd->effect[i].path);
//			str = ft_strjoin("mplayer ", snd->effect[i].path);
			str = ft_strjoin(str, ".wav&");
			system(str);
		}
		if(i == SOUNDS && ok == 0)
			ft_putendl("Sound not found.");
		i++;
	}
	return(0);
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
