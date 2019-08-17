#include "../includes/parser.h"

int		ft_error(char *str)
{
	if(str)
		ft_putendl(str);
	return(1);
}

int		play_sound(t_snd *snd, char *sound)
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
			str = ft_strjoin("afplay ", snd->effect[i].path);
//			str = ft_strjoin("mplayer ", snd->effect[i].path);
			str = ft_strjoin(str, ".wav&");
//			system(str);
//			remplacer system() -> execv(), execve() ... (appel systeme)
			printf("str in play_sound = %s\n", str);
			execv("/usr/bin/afplay", &str);
			init_pid(&snd->effect[i]);			
		}
		i++;
	}
	if(i == SOUNDS && ok == 0)
		return(ft_error("Sound not found."));
	return(0);
}

int		parserAudio(t_snd *snd)
{
	int		i;
	int		error;

	error = 0;
	i = 0;
	error = init_name(snd);
	while(i <= (SOUNDS - 1) && error == 0)
	{
		error = init_path(&snd->effect[i]);
		i++;
	}
	if(error == 1)
		return(1);
	return(0);
}
