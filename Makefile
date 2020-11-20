# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fballest <fballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 12:11:55 by fballest          #+#    #+#              #
#    Updated: 2020/11/20 14:23:38 by fballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS DISCLAIMER #

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	LIBS := -lm -lbsd -lX11 -lXext
	MLX = mlx_linux/libmlx.a
	MINILIBX = mlx_linux
	INCLUDES = -I/usr/include -I. -Iincludes/ -I$(MINILIBX) -I$(LIBFT)
endif
ifeq ($(UNAME_S), Darwin)
	LIBS := -lz -framework OpenGL -framework AppKit
	MLX = mlx_ios/libmlx.dylib
	MINILIBX = mlx_ios
	INCLUDES = -I/usr/include -I. -Iincludes/ -I$(MINILIBX) -I$(LIBFT)
endif

# FILE NAME #

NAME = Cub3D

# SOURCES #

SRC = 	ft_cub3d ft_checkmap ft_cubemain ft_freedom ft_getmap ft_utilsa \
		ft_gettexture ft_gettextureb ft_gettexturec ft_readfile ft_readfileb \
		ft_structinit ft_utilsb \

SRCCUB = $(addsuffix .c, $(SRC))
OBJS = $(SRCCUB:.c=.o)

SRCGNL = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS = $(SRCGNL:.c=.o)

LIBFT = libft/libft.a

# COMPILER #

CC = gcc -Wall -Wextra -Werror -g # -fsanitize=address

# COLOUR DEFINITION #

BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# CLEANING INSTRUCTION #

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS)
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@cd libft && make re
	@echo "$(BLUE)==========CREATING MINILIBX==========$(RESET)"
	@make -C ${MINILIBX}
	@echo "$(BLUE)==========CREATING CUBE==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJS} $(GNL_OBJS) $(LIBFT) $(MLX) ${LIBS} -o ${NAME}
	@echo "Done"
	@echo "$(BLUE)==========COPY LIBMLX.DYLIB==========$(RESET)"
	@cp ${MLX} ./
	@echo "Done"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating Cub3D file"
	#@echo "$(BLUE)==========CHECKING LEAKS==========$(RESET)"
	#@MallocStackLogging=1
	#@MallocCheckHeapStart=1000
	#@MallocCheckHeapEach=100
	#@cd /usr/local/lib
	#@sudo ln -s /Applications/Xcode.app/Contents/Developer/usr/lib/libLeaksAtExit.dylib
	#@$(LEAKS)
	#@echo "The End"

clean:
	@$(RM) $(OBJS) $(GNL_OBJS)
	@make -C $(MINILIBX)/ clean
	@make -C libft/ clean
	@$(RM) ${LIBFT}
	@${RM} libmlx.dylib
	@echo "$(GREEN)==========REMOVED==========$(RESET)"
	@echo "Success normal cleaning"

fclean: clean
	@$(RM) ${NAME}
	@$(RM) *.bmp
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"
	@echo "Success deepest cleaning"

re : fclean all

.PHONY: all clean fclean re shell addsuffix
