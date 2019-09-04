#include "../includes/parser.h"

int				ft_error(char *str)
{
	if(str)
		ft_putendl(str);
	return(1);
}

int				play_sound(t_snd *snd, char *sound, char *arg3)
{
	int			status;
	pid_t		pid;

	pid = fork();
//	init_pid(snd->effect);
	if (pid > 0)
		wait(&status);
	if (pid == 0)
	{
		ft_putendl("check line 21 parseraudio.c");
		volume(ft_atoi(arg3));
		ft_putendl("check line 23 parseraudio.c");
//		play(snd, sound);
	}
//	else
//		return(ft_error("fork: error\n"));
	return(0);
}

int				play(t_snd *snd, char *sound)
{
	int			i;
	int			ok;
	char		*tab[3];
	extern char **environ;

	i = 0;
	ok = 0;
	ft_putendl("check line 39");
	while(i < SOUNDS && ok == 0)
	{
		ft_putendl("check line 42");
		if(ft_strcmp(sound, snd->effect[i].name) == 0)
		{
			ok = 1;
			tab[0] = ft_strdup("afplay");
			tab[1] = ft_strjoin(snd->effect[i].path, ".wav");
			tab[2] = 0;
			printf("play tab[1] = %s\n", tab[1]);
			if(execve("/usr/bin/mplayer", tab, environ) == 1)
				perror("execv");
		}
		i++;
	}
	if(i == SOUNDS && ok == 0)
		return(ft_error("Sound not found."));
	return(0);
}

int				parserAudio(t_snd *snd)
{
	int			i;
	int			error;

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
