#include "../includes/parser.h"

void	init_time(t_snd *snd, FILE *wavFd)
{
	int				read;
	unsigned char	buff2[2];
	unsigned char	buff4[4];
	unsigned int	ovl_size;
	unsigned int	byterate;

	read = fread(buff4, sizeof(buff4), 1, wavFd);
	read = fread(buff4, sizeof(buff4), 1, wavFd);
	ovl_size  = 	 buff4[0] |
		(buff4[1]<<8) |
		(buff4[2]<<16) |
		(buff4[3]<<24);
	printf("Overall size (bytes:%u, Kb:%u) ... ", ovl_size, ovl_size / 1024);
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
	snd->in_seconds = (float)ovl_size / byterate;
	printf("Duration in seconds: %f\n", in_seconds);
}

int		init_path(t_snd snd)
{
	FILE		*wavFd = NULL;

	if(!(snd.efct.path = malloc(sizeof(char) * 1024)))
		return(ft_error("Error malloc filepath"));
	if(!(getcwd(snd.efct.path, 1024)))
		return(ft_error("Error parse Filename"));
	ft_strcat(snd.efct.path, "/");
	ft_strcat(snd.efct.path, snd.efct.name);
	wavFd = fopen(snd.efct.path, "rb");
	if (wavFd == NULL)
		return(ft_error("Error opening file"));
	printf("File name : %s\n", snd.efct.name);
	printf("File path : %s\n", snd.efct.path);
	init_time(&snd, wavFd);
	fclose(wavFd);
	return(0);
}
