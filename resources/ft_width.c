/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:19:25 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 15:47:34 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_hex_oct_hashtag(t_flags *flags)
{
	int			j;

	j = 0;
	while (flags->flag[j] && flags->flag[j] != 5)
		j++;
	if (flags->flag[j] == 5)
	{
		if (flags->spec == 6 || flags->spec == 7)
		{
			if (flags->width > 0)
				flags->width -= 1;
			else if (flags->prec > 0)
				flags->prec -= 1;
		}
		else if (flags->spec == 10 || flags->spec == 11 || flags->spec == 2)
			flags->width -= 2;
	}
}

void			ft_width_prec_hashtag(t_flags *flags)
{
	if (flags->prec > flags->tmp_len && flags->tmp < 0 &&
		flags->width > flags->prec)
		flags->prec -= (flags->tmp_len - 1);
	else if (flags->prec > flags->tmp_len)
		flags->prec -= flags->tmp_len;
	else
		flags->prec = 0;
	if (flags->width > flags->prec && flags->prec >= 0)
		flags->width -= flags->prec + flags->tmp_len;
	else if (flags->width > flags->tmp_len && flags->prec <= 0)
		flags->width -= flags->tmp_len;
	else
		flags->width = 0;
	ft_hex_oct_hashtag(flags);
	if (flags->width < 0)
		flags->width = 0;
	if (flags->prec < 0)
		flags->prec = 0;
}

void			ft_width_prec_sign(t_flags *flags)
{
	int			j;

	j = 0;
	while (flags->flag[j])
	{
		if (flags->flag[j] == 3 && flags->width > 0 && flags->tmp >= 0)
			flags->width -= 1;
		j++;
	}
	if (flags->tmp < 0 && flags->width == 0 && flags->prec > 0)
		flags->prec += 1;
}

void			ft_width_prec_str(t_flags *flags)
{
	if (flags->prec < 0)
		flags->prec = 0;
	if (flags->prec > 0)
		flags->width -= flags->prec;
	if (flags->spec == 0)
	{
		if (flags->prec > (int)ft_strlen(flags->str))
			flags->width -= ft_strlen(flags->str) - flags->prec;
		if (flags->prec <= 0 && flags->prec_orig != 0)
			flags->width -= ft_strlen(flags->str);
	}
	else if (flags->spec == 1)
	{
		if (flags->prec <= 0 && flags->prec_orig != 0)
			flags->width -= ft_strwlen(flags->wstr);
	}
	if (flags->width < 0)
		flags->width = 0;
}

void			ft_width_prec_percent(t_flags *flags)
{
	if (flags->spec == 12 || flags->spec == 14)
	{
		if (flags->width > 0)
			flags->width -= 1;
		if (flags->prec > 0)
			flags->prec -= 1;
	}
	else if (flags->spec == 13)
	{
		if (flags->width > ft_charwlen(flags->wc))
			flags->width -= ft_charwlen(flags->wc);
		if (flags->prec > ft_charwlen(flags->wc))
			flags->prec -= ft_charwlen(flags->wc);
	}
}
