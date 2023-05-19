# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 22:02:32 by javiersa          #+#    #+#              #
#    Updated: 2023/05/19 22:16:35 by javiersa         ###   ########.fr        #
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
SRC = src/read_map.c src/read_map2.c src/main.c src/menu.c src/picasso.c src/views.c src/picasso2.c \
src/mouse_hooks.c src/keyboard_hooks.c

# Personal use variables
PARAMS = maps/42.fdf
DATETIME := $(shell date +%Y-%m-%d' '%H:%M:%S)
GIT_BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
USER := $(shell whoami)

OBJS := $(SRC:.c=.o)

all: libftplusmake mlx42make $(PROGRAM)

nolibtool: libftplusmake2 mlx42make $(PROGRAM)

$(PROGRAM): $(NAME)
	@$(CC) $(CFLAGS) $(NAME) $(LIBFTPLUS)/libftplus.a $(MLX42)/libmlx42.a -lm -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(PROGRAM)
	@echo "$(MAGENTA)Program $(PERSONALNAME) created successfully.$(DEFAULT)"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	@echo "$(GREEN)Compiling:$(DEFAULT) $(notdir $<)"
	
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(MAGENTA)Library $(NAME) created successfully.$(DEFAULT)"
clean: libftplusclean mlx42clean
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)Removing:$(DEFAULT) All objects from $(PERSONALNAME)."
fclean: clean libftplusfclean mlx42fclean
	@$(CLEAN) ./$(NAME) ./$(PROGRAM)
	@echo "$(RED)Removing:$(DEFAULT) Library $(NAME)."
	@echo "$(RED)Removing:$(DEFAULT) Program $(PROGRAM)."
re: fclean all


libftplusmake:
	@make -C $(LIBFTPLUS)
libftplusmake2:
	@make nolibtool -C $(LIBFTPLUS)
libftplusmakeubuntu:
	@make ubuntu -C $(LIBFTPLUS)
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
	@git add *
	@echo "$(BOLD)$(YELLOW)Git ($(GIT_BRANCH)):$(WHITE) Adding all archives.$(DEFAULT)"
	@git commit -m "[$(DATETIME)] - Little changes by $(USER)"
	@echo "$(BOLD)$(CYAN)Git ($(GIT_BRANCH)):$(WHITE) Commit this changes in brunch\
	 $(GIT_BRANCH) with "[$(DATETIME)] - Little changes by $(USER)".$(DEFAULT)"
	@git push --set-upstream origin $(GIT_BRANCH)
	@echo "$(BOLD)$(GREEN)Git ($(GIT_BRANCH)):$(WHITE) Pushing all changes.$(DEFAULT)"
submodules:
	@git submodule update --init --recursive
	@echo "$(GREEN)The submodules have been created and updated successfully.$(DEFAULT)"
gitignore:
	@echo ".*\n*.out\n*.o\n*.a">.gitignore
	@echo "$(GREEN)Creating:$(DEFAULT) Gitignore."
42prepare: submodules
	@rm -rf .git*
	@echo "$(GREEN)All .git removed.$(DEFAULT)"
valgrind_datarace: $(PROGRAM)
	valgrind --tool="helgrind" ./$(PROGRAM) $(PARAMS)
valgrind_leaks: $(PROGRAM)
	valgrind --leak-check=full -s ./$(PROGRAM) $(PARAMS)

#COLORS
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
DEFAULT	:= \033[0m

.PHONY : all clean fclean re \
libftplusmake libftplusclean libftplusfclean libftplusre \
git submodules gitignore 42prepare valgrind_datarace valgrind_leaks