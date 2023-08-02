/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:56:18 by yusman            #+#    #+#             */
/*   Updated: 2023/01/30 16:44:34 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*s[1024];
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	s[fd] = readfile(fd, s[fd]);
	str = get_first_line(s[fd]);
	s[fd] = ft_trim(s[fd]);
	return (str);
}

// int	main()
// {
// 	int fd;
// 	int fd1;

// 	fd = open("text.txt", O_RDONLY);
// 	fd1 = open("text1.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd1));
// 	close(fd);
// 	close(fd1);
// }
//
// int main()
// {
// 	int fd;
// 	int fd1;
// 	fd = open("text.txt", O_RDONLY);
// 	fd1 = open("text1.txt", O_RDONLY);
// 	char *line;
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// }
