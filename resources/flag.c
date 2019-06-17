/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:58:21 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 19:50:03 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_cast_int(t_flags *flags, va_list ap)
{
	if (flags->spec == 3 || flags->spec == 5)
	{
		if (flags->len == 2)
			flags->tmp = (char)va_arg(ap, int);
		else if (flags->len == 3)
			flags->tmp = (short int)va_arg(ap, int);
		else if (flags->len == 4)
			flags->tmp = va_arg(ap, long long int);
		else if (flags->len == 5)
			flags->tmp = va_arg(ap, long int);
		else if (flags->len == 6)
			flags->tmp = va_arg(ap, long long int);
		else if (flags->len == 7)
			flags->tmp = va_arg(ap, long int);
		if ((flags->len == 4 || flags->len == 5 || flags->len == 6 ||
			flags->len == 7) && flags->tmp < 0)
		{
			flags->utmp = -1 * flags->tmp;
			flags->tmp = -1;
		}
	}
}

static void		ft_cast_long_int(t_flags *flags, va_list ap)
{
	if (flags->spec == 4)
	{
		if (flags->len == 2)
			flags->tmp = (unsigned short)va_arg(ap, long int);
		else if (flags->len == 3)
			flags->tmp = va_arg(ap, long int);
		else if (flags->len == 4)
			flags->tmp = va_arg(ap, long long int);
		else if (flags->len == 5)
			flags->tmp = va_arg(ap, long int);
		else if (flags->len == 6)
			flags->tmp = va_arg(ap, intmax_t);
		else if (flags->len == 7)
			flags->tmp = va_arg(ap, size_t);
		if ((flags->len == 4 || flags->len == 5) && flags->tmp < 0)
		{
			flags->utmp = -1 * flags->tmp;
			flags->tmp = -1;
		}
	}
}

static void		ft_cast_uint(t_flags *flags, va_list ap)
{
	if (flags->spec == 6 || flags->spec == 8 ||
			flags->spec == 10 || flags->spec == 11)
	{
		if (flags->len == 2)
			flags->utmp = (unsigned char)va_arg(ap, unsigned int);
		else if (flags->len == 3)
			flags->utmp = (unsigned short int)va_arg(ap, unsigned int);
		else if (flags->len == 4)
			flags->utmp = va_arg(ap, unsigned long long int);
		else if (flags->len == 5)
			flags->utmp = va_arg(ap, unsigned long int);
		else if (flags->len == 6)
			flags->utmp = va_arg(ap, uintmax_t);
		else if (flags->len == 7)
			flags->utmp = va_arg(ap, ssize_t);
	}
}

static void		ft_cast_long_uint(t_flags *flags, va_list ap)
{
	if (flags->spec == 7)
	{
		if (flags->len == 2)
			flags->utmp = (unsigned short)va_arg(ap, unsigned int);
		else if (flags->len == 3)
			flags->utmp = va_arg(ap, unsigned int);
		else if (flags->len == 4)
			flags->utmp = va_arg(ap, unsigned long long int);
		else if (flags->len == 5)
			flags->utmp = va_arg(ap, unsigned long int);
		else if (flags->len == 6)
			flags->utmp = va_arg(ap, uintmax_t);
		else if (flags->len == 7)
			flags->utmp = va_arg(ap, ssize_t);
	}
	if (flags->spec == 9)
		flags->utmp = va_arg(ap, unsigned long int);
}

void			ft_cast_length(t_flags *flags, va_list ap)
{
	ft_cast_int(flags, ap);
	ft_cast_long_int(flags, ap);
	ft_cast_uint(flags, ap);
	ft_cast_long_uint(flags, ap);
	if (flags->spec == 12 && flags->len == 5)
	{
		flags->wc = va_arg(ap, wint_t);
		flags->spec = 13;
	}
	else if (flags->spec == 0 && flags->len == 5)
	{
		flags->wstr = va_arg(ap, wchar_t *);
		flags->spec = 1;
	}
	else if (flags->spec == 13)
		flags->wc = va_arg(ap, wint_t);
	else if (flags->spec == 1)
		flags->wstr = va_arg(ap, wchar_t *);
	else if (flags->spec == 2)
	{
		flags->utmp = va_arg(ap, unsigned long long int);
		flags->tmp_len = ft_uintlen(flags->utmp, 16);
		flags->flag[0] = 5;
	}
}
