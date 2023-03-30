# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 22:02:32 by javiersa          #+#    #+#              #
#    Updated: 2023/03/30 20:50:35 by javiersa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a
USER = javiersa
PERSONALNAME = fdf
PROGRAM = fdf
CFLAGS = -Wall -Werror -Wextra
CC = gcc
CLEAN = rm -Rf
LIBFTPLUS = libftplus
MLX42 = MLX42
SRC = src/read_map.c src/main.c

OBJS := $(SRC:.c=.o)

all: libftplusmake mlx42make $(NAME)
	@$(CC) $(CFLAGS) $(NAME) $(LIBFTPLUS)/libftplus.a $(MLX42)/libmlx42.a -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(PROGRAM)
	@echo "$(GREEN)$(PERSONALNAME) -> Program created successfully.$(DEFAULT)"
.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(PERSONALNAME) -> Objects and library created successfully.$(DEFAULT)"
clean: libftplusclean mlx42clean
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)$(PERSONALNAME) -> Objects files deleted.$(DEFAULT)"
fclean: libftplusfclean mlx42fclean
	@$(CLEAN) ./$(OBJS)
	@$(CLEAN) ./$(NAME) $(PROGRAM)
	@echo "$(RED)$(PERSONALNAME) -> Library and objects files deleted.$(DEFAULT)"
re: libftplusre mlx42re fclean all

libftplusmake:
	@make -C $(LIBFTPLUS)
libftplusclean:
	@make clean -C $(LIBFTPLUS)
libftplusfclean:
	@make fclean -C $(LIBFTPLUS)
libftplusre: libftplusclean libftplusmake

mlx42make:
	@make -C $(MLX42)
mlx42clean:
	@make clean -C $(MLX42)
mlx42fclean:
	@make fclean -C $(MLX42)
mlx42re: libftplusclean libftplusmake

#Personal use
git: fclean gitignore
	git add *
	git commit -m "Little changes"
	git push
	git ls-files
gitignore:
	@echo ".*\n*.out\n*.o\n*.a">.gitignore
	@echo "$(GREEN)Gitignore created successfully.$(DEFAULT)"

.PHONY : all clean fclean re bonus compile git gitignore \
	libftplusmake libftplusclean libftplusfclean libftplusre
submodules:
	@git submodule update --init --recursive
	@echo "$(GREEN)The submodules have been created and updated successfully.$(DEFAULT)"

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m