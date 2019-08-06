#include "../includes/parser.h"
/*
int		init_name(t_snd *snd)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
	if(!(fd = open("sound.txt", O_RDONLY)))
		return(ft_error("Error open file."));
	while(get_next_line(fd, &line))
	{
		snd->effect[i].name = ft_strdup(line);
		i++;
	}
	snd->nb_sound = i;
	snd->effect[i].name = NULL;
	close(fd);
	return(0);
}*/

t_efct	init_mlln(t_efct effect)
{
	t_efct	*efct;

	if(!(efct = (t_efct)malloc(sizeof(t_efct))))
		return(ft_error("Error malloc init_mlln."));
	efct->name = NULL;
	efct->path = NULL;
	efct->in_seconds = 0;
	efct->ovl_size = 0;
	efct->next = NULL;
	return(efct);
}

int		init_Struct(t_snd *snd)
{
	int		i;
	int		fd;
	char	*line;
	t_efct	*stSound;

	i = 0;
	line = NULL;
	snd->nb_sound = 0;
	if(!(fd = open("sound.txt", O_RDONLY)))
		return(ft_error("Error open file."));
	if(!(stSound = malloc(sizeof(t_efct))))
		return(ft_error("Error malloc stSound."));

	stSound->next = NULL;
	if(get_next_line(fd, &line))
	{
		snd->effect = init_mlln(snd->effect);
		snd->effect.name = ft_strdup(line);
		init_path(&snd->effect);
		snd->effect.next = stSound;
		snd->nb_sound++;
		printf("name = %s\n path = %s\n", snd->effect.name, snd->effect.path);
	}
	while(get_next_line(fd, &line))
	{
		stSound = init_mlln(stSound);
		stSound->name = ft_strdup(line);
		init_path(stSound);
		free(stSound);
		stSound->next = stSound;
		snd->nb_sound++;
		printf("name = %s\n path = %s\n", stSound->name, stSound->path);
	}
	printf("nb_sound = %d\n", snd->nb_sound);
	return (0);
}

int		parserAudio(t_snd *snd)
{
	int		i;
	int		error;

	error = 0;
	i = 0;
	ft_putendl("Initialisation Parser Audio...");
//	error = init_name(snd);
	error = init_Struct(snd);
//	while(i <= (38) && error == 0)
//	{
//		error = init_path(&snd->effect[i]);
//		i++;
//	}
	return (0);
}
