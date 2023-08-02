/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 03:22:43 by yusman            #+#    #+#             */
/*   Updated: 2023/04/03 02:08:14 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "utils/gnl/get_next_line.h"

char	*readmap(t_game *game, char *file)
{
	game->fd = open(file, O_RDONLY);
	game->temp = get_next_line(game->fd);
	if_null_exit(game->temp);
	game->linelength = ft_strlen(game->temp);
	game->totallines = 0;
	game->i = 0;
	game->y = 0;
	while (game->temp)
	{
		game->temp = get_next_line(game->fd);
		game->totallines++;
	}
	close(game->fd);
	game->fd = open(file, O_RDONLY);
	game->map = mallocing(game->map, game->totallines * game->linelength);
	while (game->y < game->totallines)
	{
		game->temp = get_next_line(game->fd);
		game->j = 0;
		while (game->j < game->linelength)
			game->map[game->i++] = game->temp[game->j++];
		game->y++;
	}
	game->map[game->i] = '\0';
	return (game->map);
}

void	mapsize(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->mapcheck[y] && y < game->totallines - 1)
	{
		x = 0;
		while (game->mapcheck[y][x])
			x++;
		if (x != game->linelength - 1)
		{
			ft_printf("\n\n error, not rectangular or emptyline \n\n");
			free_and_exit(game);
		}
		y++;
	}
	if (!game->mapcheck[y])
	{
		ft_printf("\n\nInvalid map(Empty line in the map)\n\n");
		free_and_exit(game);
	}
}

void	wallchecker_x(t_game *game)
{
	int	x;

	x = 0;
	while (game->mapcheck[0][x])
	{
		if (game->mapcheck[0][x] != '1' && game->mapcheck[0][x] != '\n'
		&& game->mapcheck[0][x] != 13)
		{
			ft_printf("\n\n Incorrect Map Border\n\n");
			free_and_exit(game);
		}
		x++;
	}
	x = 0;
	while (game->mapcheck[game->totallines - 1][x])
	{
		if (game->mapcheck[game->totallines -1][x] != '1')
		{
			ft_printf("\n\n Incorrect Map Border\n\n");
			free_and_exit(game);
		}
		x++;
	}
}

void	wallchecker_y(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = ft_strlen(game->mapcheck[y]) - 1;
	while (game->mapcheck[y])
	{
		if (game->mapcheck[y][0] != '1' || game->mapcheck[y][x] != '1')
		{
			ft_printf("\n\n Incorrect map border or Empty Line\n\n");
			free_and_exit(game);
		}
		y++;
	}
	y--;
	if (game->mapcheck[y][x + 1])
	{
		ft_printf("\n Error on map(last line)\n");
		free_and_exit(game);
	}
}

void	coincount(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'C')
			game->coins++;
		i++;
	}
}
