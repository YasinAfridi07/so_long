# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusman <yusman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 08:08:39 by yusman            #+#    #+#              #
#    Updated: 2023/04/02 20:00:35 by yusman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	so_long.c parsing1.c parsing2.c keyhooks.c dfs.c \
		utils/gnl/get_next_line.c utils/gnl/get_next_line_utils.c \
		utils/utils.c utils/utils2.c utils/ft_printf/ft_printf.c \
		utils/ft_printf/ft_hex.c utils/ft_printf/ft_putchar.c \
		utils/ft_printf/ft_putstr.c utils/ft_printf/ft_putnbr.c \
		utils/ft_printf/ft_putpointer.c \
		utils/ft_printf/ft_putund.c

OBJ	= $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = so_long

$(NAME): $(OBJ)
		$(MAKE) -C MLX
		gcc -W -W -W $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -D BUFFER_SIZE=1 -Imlx -c $< -o $@

all:	$(NAME)


clean:
		rm -f $(OBJ)
		$(MAKE) clean -C mlx
fclean: clean
		rm -f $(NAME)
re:		fclean all

.PHONY:	all clean fclean re

