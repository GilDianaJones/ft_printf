/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:58:21 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 19:48:34 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_display_uint(t_flags *flags)
{
	if (flags->spec == 6 || flags->spec == 7)
	{
		if (flags->utmp == 0 && flags->prec_orig == 0 &&
			(flags->flag[0] != 5 || !flags->flag[0]))
			return ;
		ft_putnbr_oct(flags->utmp);
		flags->len_d += flags->tmp_len;
	}
	if (flags->utmp == 0 && flags->prec_orig == 0)
		return ;
	else if (flags->spec == 8 || flags->spec == 9)
	{
		ft_putnbr_uns(flags->utmp);
		flags->len_d += flags->tmp_len;
	}
	else if (flags->spec == 10 || flags->spec == 2)
	{
		ft_putnbr_hex(flags->utmp);
		flags->len_d += flags->tmp_len;
	}
	else if (flags->spec == 11)
	{
		ft_putnbr_hexup(flags->utmp);
		flags->len_d += flags->tmp_len;
	}
}

void		ft_display_int(t_flags *flags)
{
	if ((flags->spec == 3 || flags->spec == 5) &&
		!(flags->tmp == 0 && flags->prec_orig == 0))
	{
		if (flags->len == 4 || flags->len == 5 ||
			flags->len == 6 || flags->len == 7)
		{
			if (flags->tmp < 0)
			{
				ft_putnbr_uns(flags->utmp);
				flags->tmp_len -= ft_intlen(flags->tmp);
				flags->tmp_len += ft_uintlen(flags->utmp, 10) + 1;
				flags->len_d += flags->tmp_len;
				return ;
			}
		}
		ft_putnbr(ABS(flags->tmp));
		flags->len_d += flags->tmp_len;
	}
	else if (flags->spec == 4 && flags->prec_orig != 0)
	{
		flags->tmp < 0 ? ft_putnbr_uns(flags->utmp) :
			ft_putnbr(ABS(flags->tmp));
		flags->len_d += flags->tmp_len;
	}
	ft_display_uint(flags);
}

void		ft_space(t_flags *flags)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (flags->flag[i])
		i++;
	while (flags->flag[j] && flags->flag[j] != 4)
		j++;
	while (flags->flag[k] && flags->flag[k] != 3)
		k++;
	if (k != i)
		j = k;
	if (flags->flag[j] == 4 && flags->spec != 14)
	{
		ft_putchar(' ');
		flags->width -= 1;
		flags->len_d += 1;
	}
}
