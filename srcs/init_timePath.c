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
	efct->in_seconds = (float)efct->ovl_size / (float)byterate;
}

int		stop_sound(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID = %d\n", pid);	
	return(0);
}

int		vol_sound(int vol)
{
	char	*str;
	char	*volume;

//	if(vol >= 0 && vol <= 100)
	if(vol > 0 && vol <= 8)
	{
		str = "osascript -e \" set volume ";
//		str = "amixer sset 'Master' ";
		volume = ft_itoa(vol);
		str = ft_strjoin(str, volume);
		str = ft_strjoin(str, "\"");
//		str = ft_strjoin(str, "%");
		system(str);
	}
	else
		return(ft_error("Set volume from 1 to 8."));
//		return(ft_error("Set volume from 1 to 100."));
	return(0);
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
