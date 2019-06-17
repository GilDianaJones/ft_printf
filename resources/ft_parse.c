/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:31:57 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 15:50:06 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		d_parse_str(t_flags *flags)
{
	if (flags->spec == 0)
	{
		if (flags->str)
			ft_flag_prior_str(flags);
		else
		{
			if (flags->prec_orig != 0)
			{
				ft_putstr("(null)");
				flags->len_d += 6;
			}
			else
				ft_width_display_str(flags);
		}
	}
	else if (flags->spec == 1)
	{
		if (flags->wstr)
			ft_flag_prior_str(flags);
		else
		{
			ft_putstr("(null)");
			flags->len_d += 6;
		}
	}
}

void		d_parse_char(t_flags *flags)
{
	if (flags->spec == 12 || flags->spec == 13 || flags->spec == 14)
	{
		ft_width_prec_percent(flags);
		ft_flag_prior_c(flags);
	}
}

void		d_parse_uint(t_flags *flags)
{
	if (flags->spec == 6 || flags->spec == 7 || flags->spec == 8 ||
			flags->spec == 9 || flags->spec == 10 || flags->spec == 11 ||
			flags->spec == 2)
	{
		ft_width_prec_hashtag(flags);
		ft_width_prec_sign(flags);
		ft_width_backup(flags);
		ft_flag_prior_uint(flags);
	}
}

void		d_parse_int(t_flags *flags)
{
	if (flags->spec == 3 || flags->spec == 4 || flags->spec == 5)
	{
		ft_width_prec_hashtag(flags);
		ft_width_prec_sign(flags);
		ft_width_backup(flags);
		ft_flag_prior_int(flags);
	}
}
