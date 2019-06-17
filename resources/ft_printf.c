/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:31:57 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/19 08:39:26 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				ft_parsing(t_flags *flags, va_list ap, char *fmt)
{
	int				i;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] && fmt[i] == '%')
		{
			i++;
			if (ft_arg_init(&i, fmt, ap, flags))
			{
				d_parse_str(flags);
				d_parse_char(flags);
				d_parse_int(flags);
				d_parse_uint(flags);
			}
		}
		else if (fmt[i] && fmt[i] != '\0' && fmt[i] != '%')
		{
			ft_putchar(fmt[i]);
			flags->len_d += 1;
		}
		i++;
	}
}

int					ft_printf(char *fmt, ...)
{
	va_list			ap;
	t_flags			*flags;

	va_start(ap, fmt);
	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	flags->len_d = 0;
	ft_parsing(flags, ap, fmt);
	va_end(ap);
	free(flags);
	return (flags->len_d);
}
