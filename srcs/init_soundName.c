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
	close(fd);
	return(0);
}
void	get_soundInfo(t_snd *snd, char *sound)
{
	int	i;
	int	ok;

	i = 0;
	ok = 0;
	while(i < SOUNDS)
	{
		if(ft_strcmp(snd->effect[i].name, sound) == 0)
		{
			ok = 1;
			ft_putendl(snd->effect[i].name);
			ft_putendl(snd->effect[i].path);
			ft_putstr("Overall size in bytes: ");
			ft_putnbr(snd->effect[i].ovl_size);
			ft_putchar('\n');
			ft_putstr("Overall size in kb: ");
			ft_putnbr(snd->effect[i].ovl_size / 1024);
			ft_putchar('\n');
			ft_putstr("Duration in seconds: ");
			ft_putnbr(snd->effect[i].in_seconds);
			ft_putchar('\n');
			printf("printf %f\n", snd->effect[i].in_seconds);
		}
		if(i == SOUNDS && ok == 0)
			ft_putendl("Sound not found.");
		i++;
	}
}
