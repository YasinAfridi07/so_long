/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:49:13 by yusman            #+#    #+#             */
/*   Updated: 2023/04/15 02:30:21 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s != NULL && s[i])
	{
		free (s[i]);
		i++;
	}
	if (s)
	{
		free (s);
		s = NULL;
	}
}

void	hashmaker(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 256)
	{
		j = 0;
		while (j < 256)
		{
			game->valid[i][j] = 0;
			j++;
		}
		i++;
	}
}
// In this hashmaker function we set all the values of valid to 0
//	this function will turn the whole map = 0 and then we use our dfs algorithm

void	if_null_exit(char *file)
{
	if (!file)
	{
		write(2, "\nInvalid file\n", 14);
		exit(EXIT_FAILURE);
	}
}

void	free_and_exit(t_game *game)
{
	free_split(game->mapcheck);
	free(game->map);
	exit(EXIT_FAILURE);
}
// this function is used to free the map and mapcheck
// we use if_null_exit function whenever we need to free

int	bercheck(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (av[i - 1] == 'r' && av[i - 2] == 'e'
		&&av[i - 3] == 'b' && av[i - 4] == '.')
		return (0);
	ft_printf("\n\nNot a valid .ber file\n\n");
	exit(1);
}
// this is a simple function to check if the file name ends with ".ber" or not.
