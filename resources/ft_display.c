/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:19:25 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 15:46:49 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_width_display_int(t_flags *flags)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (flags->flag[j] && flags->flag[j] != 6)
		j++;
	while (flags->flag[k] && flags->flag[k] != 2)
		k++;
	if (flags->flag[k] == 2)
		j = k;
	while (i < flags->width)
	{
		if (flags->flag[j] == 6 && flags->prec <= 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		flags->len_d += 1;
		i++;
	}
}

void		ft_width_display_str(t_flags *flags)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (flags->flag[j] && flags->flag[j] != 6)
		j++;
	while (flags->flag[k] && flags->flag[k] != 2)
		k++;
	if (flags->flag[k] && flags->flag[k] == 2)
		j = k;
	while (i < flags->width)
	{
		if (flags->flag[j] && flags->flag[j] == 6)
			ft_putchar('0');
		else
			ft_putchar(' ');
		flags->len_d += 1;
		i++;
	}
}

void		ft_flag_display(t_flags *flags)
{
	int		j;

	j = 0;
	while (flags->flag[j] && flags->flag[j] != 3)
		j++;
	if (flags->flag[j] == 3 && flags->tmp >= 0 &&
		flags->spec <= 5 && flags->spec >= 3)
	{
		ft_putchar('+');
		flags->len_d += 1;
	}
	else if (flags->tmp < 0 && flags->spec >= 3 && flags->spec <= 5)
		ft_putchar('-');
}

void		ft_prec_display_int(t_flags *flags)
{
	int		i;

	i = 0;
	while (i < flags->prec)
	{
		ft_putchar('0');
		i++;
		flags->len_d += 1;
	}
}

void		ft_hashtag_display(t_flags *flags)
{
	int		j;

	j = 0;
	while (flags->flag[j] && flags->flag[j] != 5)
		j++;
	if (flags->flag[j] == 5)
	{
		if ((flags->spec == 6 || flags->spec == 7) && flags->utmp > 0)
		{
			ft_putchar('0');
			flags->len_d += 1;
		}
		else if ((flags->spec == 10 && flags->utmp > 0) || (flags->spec == 2))
		{
			ft_putstr("0x");
			flags->len_d += 2;
		}
		else if (flags->spec == 11 && flags->utmp > 0)
		{
			ft_putstr("0X");
			flags->len_d += 2;
		}
	}
}
