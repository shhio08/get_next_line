/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:59:07 by stakimot          #+#    #+#             */
/*   Updated: 2023/02/07 15:17:08 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_free(char *s)
{
	free(s);
	s = NULL;
	return (NULL);
}

char	*read_save(int fd, char *save)
{
	char	*buff;
	char	*tmp;
	int		byte;

	tmp = NULL;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1UL));
	if (!buff)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		buff[byte] = '\0';
		tmp = ft_strjoin(save, buff);
		free(save);
		save = tmp;
	}
	get_free(buff);
	if (byte == -1)
		return (get_free(save));
	return (save);
}

char	*make_line(char *save, size_t cnt)
{
	char	*line;
	size_t	l_cnt;

	l_cnt = 0;
	line = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!line)
		return (get_free(save));
	while (l_cnt < cnt)
	{
		line[l_cnt] = save[l_cnt];
		l_cnt++;
	}
	line[l_cnt] = '\0';
	return (line);
}

char	*make_save(char *save, size_t cnt)
{
	char	*new_save;
	size_t	len;
	size_t	n_cnt;

	if (save[cnt] == '\0')
		return (get_free(save));
	len = ft_strlen(save) - cnt;
	new_save = (char *)malloc(sizeof(char) * len + 1);
	if (!new_save)
		return (get_free(save));
	n_cnt = 0;
	while (save[cnt])
		new_save[n_cnt++] = save[cnt++];
	new_save[n_cnt] = '\0';
	get_free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	size_t		cnt;

	cnt = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_save(fd, save);
	if (!save)
		return (save);
	while ((save[cnt] != '\n' && save[cnt] != '\0'))
	{
		cnt++;
	}
	if (save[cnt] == '\n')
		cnt ++;
	line = make_line(save, cnt);
	save = make_save(save, cnt);
	return (line);
}

// #include <fcntl.h>
// int main()
// {
// 	int		fd;
// 	char	*gnl;
// 	fd = open("test", O_RDONLY);
// 	while (1)
// 	{
// 		gnl = get_next_line(fd);
// 		if (!gnl)
// 			break ;
// 		printf("%s", gnl);
// 		free(gnl);
// 	}
// 	// system("leaks a.out");
// 	return (0);
// }
