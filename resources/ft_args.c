/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:31:57 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 19:53:38 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_len(t_flags *flags, va_list ap)
{
	ft_cast_length(flags, ap);
	if (flags->spec == 3 || flags->spec == 4 || flags->spec == 5)
		flags->tmp_len = ft_intlen(flags->tmp);
	else if (flags->spec == 6 || flags->spec == 7)
		flags->tmp_len = ft_uintlen(flags->utmp, 8);
	else if (flags->spec == 8 || flags->spec == 9)
		flags->tmp_len = ft_uintlen(flags->utmp, 10);
	else if (flags->spec == 10 || flags->spec == 11)
		flags->tmp_len = ft_uintlen(flags->utmp, 16);
	else if (flags->spec == 12)
		flags->tmp_len = ft_charwlen(flags->wc);
}

void		ft_not_len_str_int(t_flags *flags, va_list ap)
{
	if (flags->spec == 0)
		flags->str = va_arg(ap, char *);
	else if (flags->spec == 1)
		flags->wstr = va_arg(ap, wchar_t *);
	if (flags->spec == 3 || flags->spec == 5)
	{
		flags->tmp = va_arg(ap, int);
		flags->tmp_len = ft_intlen(flags->tmp);
	}
	else if (flags->spec == 4)
	{
		flags->tmp = va_arg(ap, long int);
		if (flags->tmp < 0)
		{
			flags->utmp = -1 * flags->tmp;
			flags->tmp = -1;
			flags->tmp_len = ft_uintlen(flags->utmp, 10) + 1;
		}
		else
			flags->tmp_len = ft_intlen(flags->tmp);
	}
}

void		ft_not_len_uint(t_flags *flags, va_list ap)
{
	if (flags->spec == 6)
	{
		flags->utmp = va_arg(ap, unsigned int);
		flags->tmp_len = ft_uintlen(flags->utmp, 8);
	}
	else if (flags->spec == 7)
	{
		flags->utmp = va_arg(ap, unsigned long int);
		flags->tmp_len = ft_uintlen(flags->utmp, 8);
	}
	else if (flags->spec == 8)
	{
		flags->utmp = va_arg(ap, unsigned int);
		flags->tmp_len = ft_uintlen(flags->utmp, 10);
	}
	else if (flags->spec == 9)
	{
		flags->utmp = va_arg(ap, unsigned long int);
		flags->tmp_len = ft_uintlen(flags->utmp, 10);
	}
	else if (flags->spec == 10 || flags->spec == 11)
	{
		flags->utmp = va_arg(ap, unsigned int);
		flags->tmp_len = ft_uintlen(flags->utmp, 16);
	}
}

void		ft_not_len_ptr_c(t_flags *flags, va_list ap)
{
	int		j;

	j = 0;
	if (flags->spec == 2)
	{
		flags->utmp = va_arg(ap, unsigned long long int);
		flags->tmp_len = ft_uintlen(flags->utmp, 16);
		while (flags->flag[j] && flags->flag[j] != 0)
			j++;
		flags->flag[j] = 5;
	}
	else if (flags->spec == 12)
		flags->c = va_arg(ap, int);
	else if (flags->spec == 13)
		flags->wc = va_arg(ap, wint_t);
	else if (flags->spec == 14)
		flags->c = '%';
}

int			ft_arg_init(int *i, char *fmt, va_list ap, t_flags *flags)
{
	ft_flags_order(i, fmt, flags, ap);
	if (flags->spec == 24)
	{
		flags->width -= 1;
		if (flags->flag[0] == 2)
		{
			ft_putchar(fmt[*i + 1]);
			flags->len_d += 1;
			*i += 1;
		}
		ft_width_display_int(flags);
		return (0);
	}
	if (flags->len == 0)
	{
		ft_not_len_str_int(flags, ap);
		ft_not_len_uint(flags, ap);
		ft_not_len_ptr_c(flags, ap);
	}
	else
		ft_len(flags, ap);
	return (1);
}
