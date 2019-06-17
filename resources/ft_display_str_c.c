/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:58:21 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 19:48:48 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_display_char(t_flags *flags)
{
	if ((flags->spec == 12 || flags->spec == 14))
	{
		ft_putchar(flags->c);
		flags->len_d += 1;
	}
	else if (flags->spec == 13)
	{
		ft_putwchar(flags->wc);
		flags->len_d += ft_charwlen(flags->wc);
	}
}

void	ft_display_wstr_prec(t_flags *flags, int j, int k)
{
	flags->tmp_len = 0;
	while (flags->tmp_len < flags->prec)
		flags->tmp_len += ft_charwlen(flags->wstr[j++]);
	if (flags->tmp_len > flags->prec)
		k = j - 1;
	if (flags->len_d > 0 && flags->tmp_len > flags->prec)
	{
		j = 0;
		flags->tmp_len = 0;
		while (j < k)
			flags->tmp_len += ft_charwlen(flags->wstr[j++]);
		while ((flags->tmp_len++) < flags->prec && (flags->len_d++))
			ft_putchar(' ');
	}
	else if (flags->tmp_len <= flags->prec)
		k = j;
	j = 0;
	while (j < flags->prec && flags->wstr[j])
	{
		if (k > 0 && j == k)
			break ;
		ft_putwchar(flags->wstr[j]);
		flags->len_d += ft_charwlen(flags->wstr[j]);
		j++;
	}
}

void	ft_display_wstr(t_flags *flags)
{
	int j;
	int k;

	j = 0;
	k = 0;
	if (flags->wstr && flags->spec == 1 && ft_strwlen(flags->wstr))
	{
		if (flags->prec > 0)
			ft_display_wstr_prec(flags, 0, 0);
		else if (flags->prec <= 0 && flags->prec_orig != 0)
		{
			ft_putwstr(flags->wstr);
			flags->len_d += ft_strwlen(flags->wstr);
		}
	}
}

void	ft_display_str(t_flags *flags)
{
	int j;

	j = 0;
	if (flags->str && flags->spec == 0)
	{
		if (flags->prec > 0 && flags->prec < (int)ft_strlen(flags->str) &&
			ft_strlen(flags->str))
		{
			while (j < flags->prec)
			{
				ft_putchar(flags->str[j]);
				j++;
				flags->len_d += 1;
			}
		}
		else if (ft_strlen(flags->str) && flags->prec_orig != 0)
		{
			ft_putstr(flags->str);
			flags->len_d += ft_strlen(flags->str);
		}
	}
	ft_display_wstr(flags);
}
