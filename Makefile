# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 22:02:32 by javiersa          #+#    #+#              #
#    Updated: 2023/04/12 11:57:49 by javiersa         ###   ########.fr        #
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
SRC = src/read_map.c src/main.c src/menu.c src/picasso.c

OBJS := $(SRC:.c=.o)

all: libftplusmake mlx42make $(NAME)
	@$(CC) $(CFLAGS) $(NAME) $(LIBFTPLUS)/libftplus.a $(MLX42)/libmlx42.a -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(PROGRAM)
	@echo "$(GREEN)$(PERSONALNAME) -> Program created successfully.$(DEFAULT)"
ubuntu: libftplusmakeubuntu mlx42make $(NAME)
	@$(CC) $(CFLAGS) $(NAME) $(LIBFTPLUS)/libftplus.a $(MLX42)/libmlx42.a -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(PROGRAM)
	@echo "$(GREEN)$(PERSONALNAME) -> Program created successfully.$(DEFAULT)"
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

submodules:
	@git submodule update --init --recursive
	@echo "$(GREEN)The submodules have been created and updated successfully.$(DEFAULT)"

.PHONY : all clean fclean re bonus compile git gitignore submodules \
	libftplusmake libftplusclean libftplusfclean libftplusre

#Personal use
git: fclean gitignore
	@git add *
	@echo "$(BOLD)$(YELLOW)Git:$(WHITE) Adding all archives.$(DEFAULT)"
	@git commit -m "Little changes"
	@echo "$(BOLD)$(CYAN)Git:$(WHITE) Commit this changes with "Little changes".$(DEFAULT)"
	@git push
	@echo "$(BOLD)$(GREEN)Git:$(WHITE) Pushing all changes.$(DEFAULT)"
gitignore:
	@echo ".*\n*.out\n*.o\n*.a">.gitignore
	@echo "$(GREEN)Creating:$(DEFAULT) Gitignore."
42prepare: submodules
	@rm -rf $(LIBFT)/.git
	@rm -rf $(NEXTILE)/.git
	@rm -rf $(PRINTF)/.git
	@rm -rf .git .gitmodules
	@echo "$(GREEN)All .git removed.$(DEFAULT)"

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