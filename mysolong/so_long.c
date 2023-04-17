/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 08:19:39 by yusman            #+#    #+#             */
/*   Updated: 2023/04/17 17:56:59 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validchecker(t_game *game)
{
	check_mapfile_size(game);
	find_player(game);
	find_exit(game);
	dfs(game, game->p_x, game->p_y);
	if (game->coins == 0)
	{
		ft_printf("\n\n No Collectibles Found\n\n");
		free_and_exit(game);
	}
	else if (game->is_coin != game->coins)
	{
		ft_printf("\n All Collectibles not Collected\n");
		free_and_exit(game);
	}
	else if (game->is_exit != 1)
	{
		ft_printf("\n\n Error in map found\n\n");
		free_and_exit(game);
	}
}
// here we just go through the map and check for error and display the errors.

void	windowmaker(t_game *game)
{
	game->mlx_window = mlx_new_window(game->mlx, game->size_x * 64,
			game->size_y * 64, "so_long");
}

int	mouse_event(t_game *game)
{
	close_window(game);
	return (0);
}

void	mainchecker(t_game *game)
{
	game->moves = 0;
	game->is_exit = 0;
	game->is_coin = 0;
	game->coins = 0;
	game->is_player = 0;
	game->markexit = 0;
	mapsize(game);
	wallchecker_x(game);
	wallchecker_y(game);
	coincount(game);
	charactercheck(game);
	hashmaker(game);
	validchecker(game);
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("\n  NEED 2 ARGUMENTS  \n");
		exit (EXIT_FAILURE);
	}
	game.mlx = mlx_init();
	if (game.mlx)
	{
		bercheck(av[1]);
		game.map = readmap(&game, av[1]);
		game.mapcheck = ft_split(game.map, '\n');
		mainchecker(&game);
		windowmaker(&game);
		draw_map(&game);
		mlx_key_hook(game.mlx_window, keyhook, &game);
		mlx_hook(game.mlx_window, 17, 0, mouse_event, &game);
		mlx_loop(game.mlx);
		free(game.map);
		free_split(game.mapcheck);
	}
	return (0);
}
