/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:59:16 by yusman            #+#    #+#             */
/*   Updated: 2023/08/02 15:29:51 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_mapfile_size(t_game *game)
{
	int	i;

	i = 0;
	while (game->mapcheck[0][i] != '\0')
		i++;
	game->size_x = i;
	i = 0;
	while (game->mapcheck[i] != NULL)
		i++;
	game->size_y = i;
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size_y)
	{
		j = 0;
		while (j < game->size_x)
		{
			if (game->mapcheck[i][j] == 'P')
			{
				game->p_x = j;
				game->p_y = i;
				game->is_player++;
			}
			j++;
		}
		i++;
	}
	if (game->is_player != 1)
	{
		ft_printf("\n\n Error, No players found or More then 1 players found\n\n");
		free_and_exit(game);
	}
}

void	find_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size_y)
	{
		j = 0;
		while (j < game->size_x)
		{
			if (game->mapcheck[i][j] == 'E')
			{
				game->e_x = j;
				game->e_y = i;
				game->is_exit++;
			}
			j++;
		}
		i++;
	}
	if (game->is_exit != 1)
	{
		ft_printf("\n\nNo Exits or more than 1 Exits found!\n\n");
		free_and_exit(game);
	}
	game->is_exit = 0;
}

int	validcheck(t_game *game, int x, int y)
{
	if (game->valid[y][x] == 1)
		return (1);
	if (game->mapcheck[y][x] == '1')
		return (1);
	return (0);
}

void	dfs(t_game *game, int x, int y)
{
	int up = y - 1;
	int left = x - 1;
	int down = y + 1;
	int right = x + 1;

	game->valid[y][x] = 1;
	if (game->mapcheck[y][x] == 'C')
		game->is_coin++;
	if (game->mapcheck[y][x] == 'E')
		game->is_exit++;
	if (validcheck(game, x,up) == 0)
		dfs(game, x, up);
	if (validcheck(game, right, y) == 0)
		dfs(game, right, y);
	if (validcheck(game, x, down) == 0)
		dfs(game, x, down);
	if (validcheck(game, left, y) == 0)
		dfs(game, left, y);
}
