#include "includes/parser.h"

int		main(int ac, char **av)
{
	t_snd	snd;

	snd = *(t_snd *)malloc(sizeof(t_snd));
	parserAudio(&snd);
	if(ac >= 2)
	{
		playSound(&snd, av[1], 0, 0, VOLUME_MAX);
		if(ac == 3 && ft_strcmp(av[2], "info") == 0)
			get_SoundInfo(&snd, av[1]);
	}
	return(0);
}
