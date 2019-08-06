#include "../includes/parser.h"

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
}

int		init_Struct(t_snd *snd)
{
	int		i;
	char	*str;

	i = 0;
	while()
	{
		snd->effect[i] 		
	}
	return (0);
}

void	init_Struct(t_snd *snd)
{
	int		i;
	int		fd;
	int		*line;
	t_efct	stSound;

	i = 0;
	line = NULL;
	if(!(fd = open("sound.txt", O_RDONLY)));
		return(ft_error("Error open file."));
	stSound = malloc(sizeof(t_efct));
	while(stSound.next)
	{
		get_next_line(fd, &line);
		stSound.name = ft_strdup(line);
		stSound.next = stSound;
	}
}

int		parserAudio(t_snd *snd)
{
	int		i;
	int		error;

	error = 0;
	i = 0;
	ft_putendl("Initialisation Parser Audio...");
	error = init_name(snd);
//	error = init_Struct(snd);
	while(i <= (38) && error == 0)
	{
		error = init_path(&snd->effect[i]);
		i++;
	}
	return (0);
}
