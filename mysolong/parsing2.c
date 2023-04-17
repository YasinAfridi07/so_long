/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:22:28 by yusman            #+#    #+#             */
/*   Updated: 2023/04/17 17:59:13 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	charactercheck(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i] != '1' && game->map[i] != 'C'
			&& game->map[i] != 'E' && game->map[i] != '0'
			&& game->map[i] != 'P' && game->map[i] != '\n')
		{
			ft_printf("\n\nInvalid Character found in the map\n\n");
			free_and_exit(game);
		}
		i++;
	}
}
// here we check if there is something more then just the allowed characters in the map



void	draw_img(t_game *game, char *path, int x, int y)
{
	int	size;

	size = 64;
	x = x * size;
	y = y * size;
	game->img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	if (!game->img)
		exit(1);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, x, y);
	mlx_destroy_image(game->mlx, game->img);
}
// draw_img this is where we take the xpm files and put them in game->img,
//and then put the img to the window and later destroy the img

void	pick_img(t_game *game, char c, int x, int y)
{
	if (c == '1')
		draw_img(game, WALL, x, y);
	else if (c == '0')
		draw_img(game, SPACE, x, y);
	else if (c == 'C')
		draw_img(game, COLLECTIBLES, x, y);
	else if (c == 'E')
		draw_img(game, EXIT, x, y);
	else if (c == 'P')
	{
		draw_img(game, ME, x, y);
		game->p_x = x;
		game->p_y = y;
	}
}
// here we just initialize the characters to their to images.

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->mapcheck[y])
	{
		x = 0;
		while (game->mapcheck[y][x])
		{
			pick_img(game, game->mapcheck[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	close_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_window);
	mlx_destroy_window(game->mlx, game->mlx_window);
	free(game->map);
	free_split(game->mapcheck);
	exit(0);
}
// used to clear window and destroy window and free everything.
