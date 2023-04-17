/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:49:12 by yusman            #+#    #+#             */
/*   Updated: 2023/04/03 02:14:18 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "utils/gnl/get_next_line.h"
# include "utils/ft_printf/ft_printf.h"
# include "mlx/mlx.h"

# define WALL "./img/wall.xpm"
# define ME "./img/me.xpm"
# define SPACE "./img/spaces.xpm"
# define COLLECTIBLES "./img/collectible.xpm"
# define EXIT "./img/exit.xpm"
# define EXITEXIT "./img/exit_exit.xpm"

typedef struct s_game
{
	int		fd;
	int		linelength;
	int		totallines;
	int		y;
	int		j;
	int		i;
	int		moves;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		valid[256][256];
	int		is_exit;
	int		is_coin;
	int		is_player;
	int		coins;
	int		markexit;
	int		*mlx_window;
	char	*map;
	char	**mapcheck;
	char	*mlx;
	char	*temp;
	void	*img;
}	t_game;

char	**ft_split(char *s, char c);
void	free_and_exit(t_game *game);
void	close_window(t_game *game);
char	*readmap(t_game *game, char *file);
void	mapsize(t_game *game);
void	wallchecker_x(t_game *game);
void	wallchecker_y(t_game *game);
void	coincount(t_game *game);
void	charactercheck(t_game *game);
void	draw_img(t_game *game, char *path, int x, int y);
void	pick_img(t_game *game, char c, int x, int y);
void	draw_map(t_game *game);
void	close_window(t_game *game);
void	movescount(t_game *game, int x, int y, int flag);
void	win(t_game *game);
void	mark_exit(t_game *game, int x, int y);
int		moves(t_game *game, int x, int y);
int		keyhook(int keycode, t_game *game);
void	check_mapfile_size(t_game *game);
void	find_player(t_game *game);
void	find_exit(t_game *game);
int		validcheck(t_game *game, int x, int y);
void	dfs(t_game *game, int x, int y);
int		mouse_event(t_game *game);
void	validchecker(t_game *game);
void	windowmaker(t_game *game);
void	mainchecker(t_game *game);
void	hashmaker(t_game *game);
int		bercheck(char *av);
void	free_split(char **s);
void	if_null_exit(char *file);

#endif
