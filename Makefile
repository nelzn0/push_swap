# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/12 17:29:55 by nda-roch          #+#    #+#              #
#    Updated: 2026/05/18 17:50:20 by nda-roch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FT_PRINTF = libft/ft_printf
FT_PRINTF_LIB = $(FT_PRINTF)/libftprintf.a
INCS = incs
CFLAGS = -Wall -Wextra -Werror -I$(FT_PRINTF) -I$(INCS)
SRCS = srcs/push.c \
						srcs/swap.c \
						srcs/rotate.c \
						srcs/rrotate.c \
						srcs/disorder.c \
						srcs/push_swap.c 
OBJS = $(SRCS:.c=.o)

$(FT_PRINTF_LIB):
			$(MAKE) -C $(FT_PRINTF) 

all: $(NAME)

$(NAME): $(FT_PRINTF_LIB)	$(OBJS) 
				$(CC) $(CFLAGS) $(OBJS) -L$(FT_PRINTF) -lftprintf -o $(NAME)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(FT_PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re
