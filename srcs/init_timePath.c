#include "../includes/parser.h"

void	init_time(t_efct *efct, FILE *wavFd)
{
	int				read;
	unsigned char	buff2[2];
	unsigned char	buff4[4];
	unsigned int	byterate;

	read = fread(buff4, sizeof(buff4), 1, wavFd);
	read = fread(buff4, sizeof(buff4), 1, wavFd);
	efct->ovl_size  = 	 buff4[0] |
		(buff4[1]<<8) |
		(buff4[2]<<16) |
		(buff4[3]<<24);
	read = fread(buff4, sizeof(buff4), 1, wavFd);
	read = fread(buff4, sizeof(buff4), 1, wavFd);
	read = fread(buff4, sizeof(buff4), 1, wavFd);
	read = fread(buff2, sizeof(buff2), 1, wavFd);
	read = fread(buff2, sizeof(buff2), 1, wavFd);
	read = fread(buff4, sizeof(buff4), 1, wavFd);
	read = fread(buff4, sizeof(buff4), 1, wavFd);
	byterate  =	 buff4[0] |
		(buff4[1] << 8) |
		(buff4[2] << 16) |
		(buff4[3] << 24);
	efct->in_seconds = (float)efct->ovl_size / byterate;
}

void			get_SoundInfo(t_snd *snd, char *sound)
{
	int	i;

	i = 0;
	while(snd->effect[i].name != NULL)
	{
		if(ft_strcmp(snd->effect[i].name, sound) == 0)
		{
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
			printf("printf %f", snd->effect[i].in_seconds);
		}
		i++;
	}
}

int			init_path(t_efct *efct)
{
	char	*str;
	FILE	*wavFd;

	wavFd = NULL;
	if(!(efct->path = malloc(sizeof(char) * 1024)))
		return(ft_error("Error malloc filepath"));
	if(!(getcwd(efct->path, 1024)))
		return(ft_error("Error parse Filename"));
	ft_strcat(efct->path, "/srcs/sounds/");
	ft_strcat(efct->path, efct->name);
	str = ft_strjoin(efct->path, ".wav");
	wavFd = fopen(str, "rb");
	if (wavFd == NULL)
		return(ft_error("Error opening file"));
	init_time(efct, wavFd);
	fclose(wavFd);
	return(0);
}
