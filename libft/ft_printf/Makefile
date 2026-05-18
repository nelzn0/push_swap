# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/29 13:57:03 by nda-roch          #+#    #+#              #
#    Updated: 2026/05/01 19:13:11 by nda-roch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRCS = srcs/ft_printf.c \
			 srcs/ft_conversion.c \
			 srcs/ft_putchar.c \
			 srcs/ft_putstr.c \
			 srcs/ft_putnbr.c \
			 srcs/ft_putnbr_u.c \
			 srcs/ft_puthex.c \
			 srcs/ft_putptr.c 
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)
	
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
