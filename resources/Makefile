# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gthomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 15:18:38 by gthomas           #+#    #+#              #
#    Updated: 2016/12/17 17:44:20 by gthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = flag.c \
	   ft_printf.c \
	   ft_printf_tools.c \
	   ft_width.c \
	   ft_configs_1.c \
	   ft_configs_2.c \
	   ft_configs_3.c \
	   ft_configs_4.c \
	   ft_config_int.c \
	   ft_config_uint.c \
	   ft_config_c.c \
	   ft_config_str.c \
	   ft_display.c \
	   ft_width_backup.c \
	   ft_parse.c \
	   ft_init.c \
	   ft_args.c \
	   ft_display_int_uint.c \
	   ft_display_str_c.c

OBJS = $(SRCS:.c=.o)

HEADER = ../includes/ft_printf.h

all: $(OBJS)

$(OBJS):
	@gcc -Wall -Werror -Wextra -c $< $(SRCS) -I$(HEADER)

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(HEADER).gch

re: fclean all
