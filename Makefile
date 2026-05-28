# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/12 17:29:55 by nda-roch          #+#    #+#              #
#    Updated: 2026/05/28 14:18:29 by nda-roch         ###   ########.fr        #
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
						srcs/get_disorder.c \
						srcs/push_swap.c \
						srcs/parse.c \
						srcs/utils.c \
						srcs/node_management.c \
						srcs/normalize.c \
						srcs/get_pos.c \
						srcs/selection_sort.c \
						srcs/chunk_sort.c \
						srcs/radix_sort.c \
						srcs/sort_three.c \
						srcs/benchmark.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(FT_PRINTF_LIB)	$(OBJS) 
				$(CC) $(CFLAGS) $(OBJS) -L$(FT_PRINTF) -lftprintf -o $(NAME)

$(FT_PRINTF_LIB):
			$(MAKE) -C $(FT_PRINTF) 

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(FT_PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re
