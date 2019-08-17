#include "../includes/parser.h"

int		ft_error(char *str)
{
	if(str)
		ft_putendl(str);
	return(1);
}

pid_t	create_process(void)
{
	pid_t pid;

	pid = fork();
	while ((pid == -1) && (errno == EAGAIN));
	
	return pid;
}

int		play_sound(t_snd *snd, char *sound)
{
	int		i;
	int		ok;
	pid_t	pid;
	char	*tab[3];

	i = 0;
	ok = 0;
	pid = create_process();
	perror("fork");
	while(i < SOUNDS)
	{
		if(ft_strcmp(sound, snd->effect[i].name) == 0)
		{
			ok = 1;
			tab[0] = ft_strdup("afplay");
			tab[1] = ft_strjoin(snd->effect[i].path, ".wav");
			tab[2] = 0;
			if(execv("/usr/bin/afplay", tab) == 1)
				perror("execv");
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
