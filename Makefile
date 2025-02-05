# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abergman <abergman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 17:37:37 by abergman          #+#    #+#              #
#    Updated: 2025/02/05 21:18:38 by abergman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D
UNAME			= $(shell uname)

CC				= @cc
OBJDIR 			= bin
SRC				:= $(shell find srcs/ get_next_line/ -type f -name "*.c")

OBJS			:= $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

HEADERS 		= ./header/cub3D.h
LIBFT			= ./libft/libft.a

FSANITAIZE		= -fsanitize=address,leak,undefined
DEBUG			= -g3
CFLAGS			= -Wall -Wextra -Werror $(DEBUG)

RM				= @rm -f

MLX_DIR			= ./mlx
MLX_LIB			= $(MLX_DIR)/libmlx_$(UNAME).a
MLX_FLAGS		= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

all: $(MLX_LIB) $(NAME)

$(OBJDIR)/%.o: ./%.c $(HEADERS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJDIR) $(HEADERS) $(OBJS)
		$(CC)  $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX_FLAGS)
		@echo "$(GREEN)$(BOLD)[ ★ SUCCESS ★ ]$(BOLD_R)$(RESET): You can use './cub3D' for execute."

mlx:
		@mkdir mlx;
		git clone https://github.com/42Paris/minilibx-linux.git mlx;

$(MLX_LIB):
		@make -C $(MLX_DIR)

$(LIBFT):
	@make -C ./libft bonus --no-print-directory -s
		
$(OBJDIR):
	@mkdir $@

clean:
	$(RM) -rf $(OBJDIR)
	@make -C ./libft clean --no-print-directory

fclean: clean
	$(RM) $(NAME)
	@make -C ./libft fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re mlx

BOLD	= \e[1m
BOLD_R	= \e[0m

GREEN	= \033[0;32m
RESET	= \033[0m
