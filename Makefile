# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 17:37:37 by abergman          #+#    #+#              #
#    Updated: 2025/02/17 12:09:32 by hsharame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

CC				= cc
OBJDIR 			= ./bin
INCLUDE_DIR 	= ./header
INCLUDE_FILE	= $(INCLUDE_DIR)/cub3D.h
SRC				:= $(shell find srcs/ get_next_line/ -type f -name "*.c")

OBJS			:= $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

HEADERS 		= -I$(INCLUDE_DIR) -I./libft
LIBFT			= ./libft/libft.a

DEBUG			= -g3
CFLAGS			= -Wall -Wextra -Werror -o3 $(DEBUG)

RM				= @rm

MLX_DIR			= ./mlx
MLX_LIB			= $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS		= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

all: $(MLX_LIB) $(NAME)

$(OBJDIR)/%.o: ./%.c $(INCLUDE_FILE)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(LIBFT)  $(OBJDIR) $(OBJS)
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
	$(RM) -f $(NAME)
	@make -C ./libft fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re mlx

BOLD	= \e[1m
BOLD_R	= \e[0m

GREEN	= \033[0;32m
RESET	= \033[0m
