# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apeyret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 18:24:48 by apeyret           #+#    #+#              #
#    Updated: 2019/06/20 15:16:08 by apeyret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -I inc/ -Wall -Werror -Wextra -g

INC_DIR = inc

INC_FILE = get_next_line.h \
		   libft.h

SRC_DIR = src

SRC_FILE =	ft_atoi.c \
			ft_bzero.c \
			ft_cisin.c \
			ft_isalldigit.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_lstadd.c \
			ft_lstisin.c \
			ft_lstiter.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_rereplace.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strequ.c \
			ft_strichr.c \
			ft_strisdigit.c \
			ft_strisprint.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strlower.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_tabcmp.c \
			ft_tablen.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_util.c \
			get_next_line.c \

OBJ_DIR = .obj
OBJ_FILE = $(SRC_FILE:.c=.o)

CRT_DIR = .

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILE))
INC = $(addprefix $(INC_DIR)/,$(INC_FILE))
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_FILE))
CRT = $(addprefix $(OBJ_DIR)/,$(CRT_DIR))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) Makefile
	@printf "\033[0;32m[Libft] Compilation [o.]\033[0;0m\r"
	@mkdir -p $(CRT) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m[Libft] Compilation [.o]\033[0;0m\r"

norm:
	@norminette $(SRC)
	@norminette $(INC)

$(NAME): $(OBJ)
	@printf "\033[0;32m[Libft] Compilation [OK]\033[0;0m\n"
	@ar rc $(NAME) $(OBJ) 
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(OBJ_DIR)
	@printf "\033[0;31m[Libft] Deleted *.o\033[0;0m\n"

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
