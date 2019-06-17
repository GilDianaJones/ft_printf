/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_configs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:10:45 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 15:22:06 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_config_5(t_flags *flags)
{
	ft_space(flags);
	ft_hashtag_display(flags);
	ft_flag_display(flags);
	ft_width_display_int(flags);
	if (flags->width > 0 && flags->prec <= 0)
		ft_display_int(flags);
	ft_prec_display_int(flags);
	if (flags->prec > 0 || (flags->width == 0 && flags->prec == 0))
		ft_display_int(flags);
}

void		ft_config_6(t_flags *flags)
{
	ft_space(flags);
	ft_width_display_int(flags);
	ft_hashtag_display(flags);
	ft_flag_display(flags);
	ft_prec_display_int(flags);
	ft_display_int(flags);
}

void		ft_config_7(t_flags *flags)
{
	ft_width_display_str(flags);
	ft_display_char(flags);
}

void		ft_config_8(t_flags *flags)
{
	ft_display_char(flags);
	ft_width_display_str(flags);
}
