/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_configs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:10:45 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 14:13:35 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_config_0_0(t_flags *flags)
{
	if (flags->spec != 2 || flags->flag[0] != 6)
	{
		ft_width_display_int(flags);
		ft_flag_display(flags);
		ft_hashtag_display(flags);
		ft_display_int(flags);
	}
	else if (flags->spec == 2 && flags->flag[0] == 6)
		ft_config_1(flags);
}

static void		ft_config_0_1(t_flags *flags)
{
	ft_width_display_int(flags);
	ft_hashtag_display(flags);
	ft_flag_display(flags);
	ft_prec_display_int(flags);
	ft_display_int(flags);
}

static void		ft_config_0_2(t_flags *flags)
{
	if (flags->tmp < 0)
		ft_flag_display(flags);
	ft_width_display_int(flags);
	ft_hashtag_display(flags);
	ft_prec_display_int(flags);
	if (flags->tmp >= 0)
		ft_flag_display(flags);
	ft_display_int(flags);
}

void			ft_config_0(t_flags *flags)
{
	if (flags->tmp >= 0 && flags->spec >= 3 && flags->spec <= 5)
	{
		ft_space(flags);
		if (flags->width < 0)
			flags->width = 0;
	}
	if (flags->width > 0 && flags->prec <= 0)
		ft_config_0_0(flags);
	else if (flags->prec > 0 && flags->width > 0)
		ft_config_0_1(flags);
	else if (flags->prec > 0 || (flags->width == 0 && flags->prec == 0))
		ft_config_0_2(flags);
}
