/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:33:02 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 14:12:51 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_specifiers(char c)
{
	int		ret;
	char	*tab;

	tab = "sSpdDioOuUxXcC%eEfFgGaAn";
	ret = 0;
	while (tab[ret] && tab[ret] != c)
		ret++;
	if (tab[ret] != c)
		ret = 24;
	return (ret);
}

int			ft_flags(int *i, char *fmt)
{
	if (fmt[*i] && (fmt[*i] == '-' || fmt[*i] == '+' || fmt[*i] == ' ' ||
		fmt[*i] == '#' || fmt[*i] == '0'))
	{
		*i += 1;
		if (fmt[*i - 1] && fmt[*i - 1] == '-')
			return (2);
		else if (fmt[*i - 1] && fmt[*i - 1] == '+')
			return (3);
		else if (fmt[*i - 1] && fmt[*i - 1] == ' ')
			return (4);
		else if (fmt[*i - 1] && fmt[*i - 1] == '#')
			return (5);
		else if (fmt[*i - 1] && fmt[*i - 1] == '0')
			return (6);
	}
	return (0);
}

int			ft_width(int *i, char *fmt)
{
	int i_cpy;

	i_cpy = *i;
	if ((fmt[*i] - '0') > 0 && (fmt[*i] <= '9'))
	{
		*i += ft_intlen(ft_atoi(fmt + i_cpy));
		return (ft_atoi(fmt + i_cpy));
	}
	else if (fmt[*i + 1] == '*')
	{
		*i += 1;
		return (-1);
	}
	else
		return (0);
}

int			ft_precision(int *i, char *fmt)
{
	int i_cpy;

	i_cpy = 0;
	if (fmt[*i] == '.')
	{
		*i += 1;
		if (fmt[*i] == '*')
		{
			*i += 1;
			return (-1);
		}
		else if (fmt[*i] >= '0' && fmt[*i] <= '9')
		{
			i_cpy = *i;
			*i += ft_intlen(ft_atoi(fmt + i_cpy));
			return (ft_atoi(fmt + i_cpy));
		}
		else
			return (0);
	}
	else
		return (-2);
}

int			ft_length(int *i, char *fmt)
{
	if (fmt[*i] && (fmt[*i] == 'h' || fmt[*i] == 'l' || fmt[*i] == 'j' ||
		fmt[*i] == 'z'))
	{
		*i += 1;
		if (fmt[*i - 1] == 'h' && fmt[*i] && fmt[*i] != 'h')
			return (3);
		else if (fmt[*i - 1] == 'h' && fmt[*i] && fmt[*i] == 'h')
		{
			*i += 1;
			return (2);
		}
		else if (fmt[*i - 1] == 'l' && fmt[*i] && fmt[*i] != 'l')
			return (5);
		else if (fmt[*i - 1] == 'l' && fmt[*i] && fmt[*i] == 'l')
		{
			*i += 1;
			return (4);
		}
		else if (fmt[*i - 1] == 'j')
			return (6);
		else if (fmt[*i - 1] == 'z')
			return (7);
	}
	return (0);
}
