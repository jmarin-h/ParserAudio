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
	int		status;
	int		ok;
	pid_t	pid;
	char	*tab[3];

	i = 0;
	ok = 0;
	while(i < SOUNDS && ok == 0)
	{
		if(ft_strcmp(sound, snd->effect[i].name) == 0)
		{
			ok = 1;
			pid = fork();
			if (pid == 0)
			{
				extern char **environ;
				tab[0] = ft_strdup("afplay");
				tab[1] = ft_strjoin(snd->effect[i].path, ".wav");
				tab[2] = 0;
				init_pid(&snd->effect[i]);
				if(execve("/usr/bin/afplay", tab, environ) == 1)
					perror("execv");
			}
			else if (pid > 0)
				wait(&status);
			else
				printf("fork: error\n");
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
