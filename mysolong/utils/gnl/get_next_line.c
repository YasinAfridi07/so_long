/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:00:52 by yusman            #+#    #+#             */
/*   Updated: 2023/04/03 02:01:21 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfile(int fd, char *s)
{
	char	*buff;
	int		ret;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret != '\0')
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = '\0';
		s = ft_strjoin(s, buff);
		if (check_newline(s))
			break ;
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	s = readfile(fd, s);
	str = get_first_line(s);
	s = ft_trim(s);
	return (str);
}

int	check_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
