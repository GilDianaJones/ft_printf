# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gthomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 15:18:38 by gthomas           #+#    #+#              #
#    Updated: 2016/12/17 13:01:13 by gthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_LIBFT = ft_putchar.c \
			 ft_intlen.c \
			 ft_uintlen.c \
			 ft_atoi.c \
			 ft_putnbr_uns.c \
			 ft_putnbr_oct.c \
			 ft_putnbr_hexup.c \
			 ft_putnbr_hex.c \
			 ft_putnbr.c \
			 ft_putstr.c \
			 ft_strlen.c \
			 ft_itoa.c \
			 ft_strdup.c \
			 ft_wchar.c

OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)

HEADER_LIBFT = ../includes/libft.h

all: $(OBJS_LIBFT)

$(OBJS_LIBFT):
	@gcc -Wall -Werror -Wextra -c $(SRCS_LIBFT) -I$(HEADER_LIBFT)

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJS_LIBFT)

fclean: clean
	@rm -rf $(HEADER_LIBFT).gch

re: fclean all
