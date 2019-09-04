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

int			init_pid(t_efct *efct)
{
	efct->pid = getpid();
	efct->pid += 2;
	printf("PID in init_pid = %d\n", efct->pid);	
	return(0);
}

int			stop_sound(t_snd *snd, char *sound)
{
	int 	i;
	int		ok;

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

int			volume(int vol)
{
	char	*tab[5];
	char	*str;

	if(vol >= 1 && vol <= 8)
	{
//		str = ft_strjoin("-e \"set volume ", ft_itoa(vol));
//		str = ft_strjoin("sset 'Master' ", ft_itoa(vol));
		tab[0] = ft_strdup("osascript"); 	/*osascript   ---  amixer*/
		tab[1] = ft_strdup("/osascript");	/*osascript   ---  amixer*/
		tab[2] = ft_strdup("-e");	/*	 -e   ---    sset*/
//		tab[3] = ft_strdup("\"set volume");	/*"set volume" - 'Master'*/
		tab[3] = ft_strjoin("set volume ", ft_itoa(vol));	/*"set volume" - 'Master'*/
//		tab[4] = ft_strjoin(ft_itoa(vol), "\""); /* "\" --- "%" */
//		tab[3] = ft_strjoin(tab[3], "\""); /* "\" --- "%" */
		tab[4] = (char *)NULL;
		printf("tab = '%s' '%s' '%s' '%s' '%s'\n", tab[0],
				tab[1], tab[2], tab[3], tab[4]);
		if(execlp(tab[0], tab[1], tab[2], tab[3], tab[4]) == -1)
			return(ft_error("Error execlp."));
//			perror("execlp");
		ft_putendl("line 82 : here is ok");
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
