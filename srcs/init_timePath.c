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

int		init_pid(t_efct *efct)
{
	efct->pid = getpid();
	efct->pid += 2;
	printf("PID in init_pid = %d\n", efct->pid);	
	return(0);
}

int		stop_sound(t_snd *snd, char *sound)
{
	int i;
	int	ok;

	i = 0;
	ok = 0;
	while(i < SOUNDS)
	{
		if(ft_strcmp(sound, snd->effect[i].name) == 0)
		{
			ok = 1;
		printf("PID in stop_sound = %d\n", snd->effect[i].pid);	
			kill(snd->effect[i].pid, SIGKILL);
		}
		i++;
	}
	if(i == SOUNDS && ok == 0)
		return(ft_error("Sound not found.."));
	return(0);
}

int		vol_sound(int vol)
{
	pid_t	pid;
	char	*tab[3];
	char	*str;
	char	*volume;

	if(vol > 0 && vol <= 100)
	{
//		str = ft_strjoin("-e \"set volume ", ft_itoa(vol));
//		str = ft_strjoin("sset 'Master' ", ft_itoa(vol));
//		tab[0] = ft_strdup("amixer");  /* "osascript" */
//		tab[1] = ft_strjoin(str, "%"); /* "\"" */
//		tab[2] = NULL;
//		printf("tab[1] = %s\n", tab[1]);
//		pid = fork();
//		while(1)
//		{
//			if(pid == 0)
//				wait(NULL);
//			if (pid)
//			{
		execlp(tab[0], tab[1], tab[2]);
//				break;
//			}
//		}
//		system(str);
	}
	else
		return(ft_error("Set volume from 1 to 8."));
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
