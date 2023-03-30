# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 22:02:32 by javiersa          #+#    #+#              #
#    Updated: 2023/03/30 17:42:24 by javiersa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a
PERSONALNAME = fdf
PROGRAM = fdf
CFLAGS = -Wall -Werror -Wextra
CC = gcc
CLEAN = rm -Rf
LIBFTPLUS = libftplus
SRC = src/read_map.c

OBJS := $(SRC:.c=.o)

all: libftplusmake $(NAME)
	@$(CC) $(CFLAGS) $(NAME) $(LIBFTPLUS)/libftplus.a -o $(PROGRAM)
	@echo "$(GREEN)$(PERSONALNAME) -> Program created successfully.$(DEFAULT)"
.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(PERSONALNAME) -> Objects and library created successfully.$(DEFAULT)"
clean: libftplusclean
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)$(PERSONALNAME) -> Objects files deleted.$(DEFAULT)"
fclean: libftplusfclean
	@$(CLEAN) ./$(OBJS)
	@$(CLEAN) ./$(NAME) $(PROGRAM)
	@echo "$(RED)$(PERSONALNAME) -> Library and objects files deleted.$(DEFAULT)"
re: libftplusre fclean all

libftplusmake:
	@make -C $(LIBFTPLUS)
libftplusclean:
	@make clean -C $(LIBFTPLUS)
libftplusfclean:
	@make fclean -C $(LIBFTPLUS)
libftplusre: libftplusclean libftplusmake

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