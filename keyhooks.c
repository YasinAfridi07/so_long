/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:52:38 by yusman            #+#    #+#             */
/*   Updated: 2023/08/02 15:16:36 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movescount(t_game *game, int x, int y, int flag)
{
	if (flag == 1)
		ft_printf("Moves: %d\n", ++game->moves);
	if (game->mapcheck[y][x] == 'C')
	{
		game->mapcheck[y][x] = '0';
		game->coins--;
	}
	game->p_x = x;
	game->p_y = y;
}

void	win(t_game *game)
{
	if (game->coins <= 0 && game->mapcheck[game->p_y][game->p_x] == 'E')
	{
		ft_printf("\n\nGAME OVER! YOU WIN\n\n");
		close_window(game);
	}
}

void	mark_exit(t_game *game, int x, int y)
{
	if (game->markexit == 1 && game->mapcheck[y][x] != 'E')
	{
		draw_img(game, EXIT, game->e_x, game->e_y);
		game->markexit = 0;
	}
}

int	moves(t_game *game, int x, int y)
{
	if (game->mapcheck[game->p_y + y][game->p_x + x] == '1')
		return (0);
	else if (game->mapcheck[game->p_y + y][game->p_x + x] == 'E'
	&& game->coins > 0)
	{
		draw_img(game, SPACE, game->p_x, game->p_y);
		draw_img(game, EXITEXIT, game->p_x + (x), game->p_y + (y));
		movescount(game, game->p_x + (x), game->p_y + (y), 1);
		game->markexit = 1;
	}
	else
	{
		draw_img(game, SPACE, game->p_x, game->p_y);
		draw_img(game, ME, game->p_x + x, game->p_y + y);
		movescount(game, game->p_x + x, game-> p_y + y, 1);
		mark_exit(game, game->p_x + x, game->p_y + y);
		win(game);
	}
	return (0);
}

int	keyhook(int keycode, t_game *game)
{
	int up = 13;
	int down = 1;
	int right = 2;
	int left = 0;
	int esc = 53;

	int move_up_on_y = -1;
	int move_left_on_x = -1;
	int move_down_on_y = 1;
	int move_right_on_x = 1;

	if (keycode == up)
		moves(game, 0, move_up_on_y);
	else if (keycode == left)
		moves(game, move_left_on_x, 0);
	else if (keycode == down)
		moves(game, 0, move_down_on_y);
	else if (keycode == right)
		moves(game, move_right_on_x, 0);
	else if (keycode == esc)
		close_window(game);
	return (0);
}
