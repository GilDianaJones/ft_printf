/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:12:29 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 14:16:45 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_flag_minus(t_flags *flags)
{
	if (flags->flag[1] && flags->flag[1] == 3 && flags->prec <= 0)
		ft_config_1(flags);
	else if (flags->flag[1] && flags->flag[1] == 3 && flags->prec > 0)
		ft_config_3(flags);
	else if (flags->flag[1] && flags->flag[1] == 6)
		ft_config_3(flags);
	else if (flags->prec > 0)
		ft_config_3(flags);
	else
		ft_config_1(flags);
}

static void		ft_flag_plus(t_flags *flags)
{
	if (flags->flag[1] && flags->flag[1] == 6 &&
		flags->width > 0 && flags->prec <= 0)
		ft_config_5(flags);
	else if (flags->prec > 0 && flags->width <= 0)
		ft_config_3(flags);
	else if (flags->prec > 0 && flags->width > 0)
		ft_config_6(flags);
	else
		ft_config_0(flags);
}

static void		ft_flag_space(t_flags *flags)
{
	ft_config_0(flags);
}

static void		ft_flag_zero(t_flags *flags)
{
	if (flags->flag[1] && flags->flag[1] == 3)
		ft_config_2(flags);
	else if (flags->flag[1] && flags->flag[1] == 2)
		ft_config_1(flags);
	else
		ft_config_2(flags);
}

void			ft_flag_prior_int(t_flags *flags)
{
	if (flags->flag[0])
	{
		if (flags->flag[0] == 2)
			ft_flag_minus(flags);
		else if (flags->flag[0] == 3)
			ft_flag_plus(flags);
		else if (flags->flag[0] == 4)
			ft_flag_space(flags);
		else if (flags->flag[0] == 6)
			ft_flag_zero(flags);
		else
			ft_config_0(flags);
	}
	else
		ft_config_0(flags);
}
