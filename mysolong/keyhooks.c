/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:52:38 by yusman            #+#    #+#             */
/*   Updated: 2023/04/07 22:02:47 by yusman           ###   ########.fr       */
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
// here we are counting the moves that should be displayed on the shell.
// and we also count the coins in the map.

void	win(t_game *game)
{
	if (game->coins <= 0 && game->mapcheck[game->p_y][game->p_x] == 'E')
	{
		ft_printf("\n\nGAME OVER! YOU WIN\n\n");
		close_window(game);
	}
}
// here we display "you win" when the coins are all collected and the player is at the Exit.

void	mark_exit(t_game *game, int x, int y)
{
	if (game->markexit == 1 && game->mapcheck[y][x] != 'E')
	{
		draw_img(game, EXIT, game->e_x, game->e_y);
		game->markexit = 0;
	}
}
// 

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
// this function is easy to understand, here we say if the Character is at the exit and the coins are not all collected,
// we just place the images and dont allow the game to end since we havent taken all the coins.

int	keyhook(int keycode, t_game *game)
{
	if (keycode == 13)
		moves(game, 0, -1);
	else if (keycode == 0)
		moves(game, -1, 0);
	else if (keycode == 1)
		moves(game, 0, 1);
	else if (keycode == 2)
		moves(game, 1, 0);
	else if (keycode == 53)
		close_window(game);
	return (0);
}
// here we define our keys.. i have used here the keyword code
// 13 being the 'W' key, 0 is the 'A' key, 1 is the 'S' key and 2 is the 'D' key;
// in this function we say if those keycode is true we call the moves function to make the move.
