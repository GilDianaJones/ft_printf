# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gthomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 15:18:38 by gthomas           #+#    #+#              #
#    Updated: 2016/12/17 17:44:53 by gthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./resources/flag.c \
	   ./resources/ft_printf.c \
	   ./resources/ft_printf_tools.c \
	   ./resources/ft_width.c \
	   ./resources/ft_configs_1.c \
	   ./resources/ft_configs_2.c \
	   ./resources/ft_configs_3.c \
	   ./resources/ft_configs_4.c \
	   ./resources/ft_config_int.c \
	   ./resources/ft_config_uint.c \
	   ./resources/ft_config_c.c \
	   ./resources/ft_config_str.c \
	   ./resources/ft_display.c \
	   ./resources/ft_width_backup.c \
	   ./resources/ft_parse.c \
	   ./resources/ft_init.c \
	   ./resources/ft_args.c \
	   ./resources/ft_display_int_uint.c \
	   ./resources/ft_display_str_c.c

SRCS_LIBFT = ./srcs/ft_putchar.c \
			 ./srcs/ft_intlen.c \
			 ./srcs/ft_uintlen.c \
			 ./srcs/ft_atoi.c \
			 ./srcs/ft_putnbr_uns.c \
			 ./srcs/ft_putnbr_oct.c \
			 ./srcs/ft_putnbr_hexup.c \
			 ./srcs/ft_putnbr_hex.c \
			 ./srcs/ft_putnbr.c \
			 ./srcs/ft_putstr.c \
			 ./srcs/ft_strlen.c \
			 ./srcs/ft_itoa.c \
			 ./srcs/ft_strdup.c \
			 ./srcs/ft_wchar.c

OBJS = $(SRCS:.c=.o)

OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)

all: $(NAME)

$(NAME):
	@cd ./srcs/ && Make re
	@cd ./resources/ && Make re
	@ar rc $(NAME) $(OBJS) $(OBJS_LIBFT)
	@ranlib $(NAME)

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(HEADER).gch
	@rm -rf $(HEADER_LIBFT).gch

re: fclean all
