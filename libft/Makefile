# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fballest <fballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 11:07:39 by fballest          #+#    #+#              #
#    Updated: 2020/10/06 09:00:41 by fballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean all fclean re bonus rebonus

NAME = libft.a

HEADER = libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_calloc.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c\
		ft_memcmp.c	ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c\
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c\
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c\
		ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		ft_itoa.c ft_putnbr_fd.c ft_strtrim.c ft_strmapi.c ft_split.c

BONUSSRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRCS:.c=.o)

OBJBONUS = $(BONUSSRCS:.c=.o)

LIB = ar -rcs

RM = rm -rf

all:		$(NAME) bonus

$(NAME):$(OBJ) $(HEADER)
			@$(CC) $(CFLAGS) -c $(SRCS) -I./includes/
			@$(LIB) $(NAME) $(OBJ) $(HEADER)
			@ranlib $(NAME)

bonus:$(OBJBONUS) $(HEADER)
			@$(CC) $(CFLAGS) -c $(BONUSSRCS) -I./includes/
			@$(LIB) $(NAME) $(OBJBONUS) $(HEADER)
			@ranlib $(NAME)

clean:
			@$(RM) $(OBJ) $(OBJBONUS)

fclean: 	clean
			@$(RM) $(NAME)

re: 		fclean all

rebonus:	fclean bonus
