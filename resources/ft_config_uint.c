/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:12:29 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 14:19:05 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_flag_hashtag(t_flags *flags)
{
	if (flags->flag[1] && flags->flag[1] == 6)
	{
		if (flags->flag[2] && flags->flag[2] == 2)
			ft_config_3(flags);
		ft_config_2(flags);
	}
	else if (flags->flag[1] && flags->flag[1] == 2)
		ft_config_3(flags);
	else
		ft_config_0(flags);
}

static void		ft_flag_minus(t_flags *flags)
{
	if (flags->flag[1] && flags->flag[1] == 5)
		ft_config_3(flags);
	else
		ft_config_3(flags);
}

static void		ft_flag_space(t_flags *flags)
{
	ft_config_0(flags);
}

static void		ft_flag_zero(t_flags *flags)
{
	ft_config_0(flags);
}

void			ft_flag_prior_uint(t_flags *flags)
{
	if (flags->flag[0])
	{
		if (flags->flag[0] == 2)
			ft_flag_minus(flags);
		else if (flags->flag[0] == 4)
			ft_flag_space(flags);
		else if (flags->flag[0] == 5)
			ft_flag_hashtag(flags);
		else if (flags->flag[0] == 6)
			ft_flag_zero(flags);
		else
			ft_config_0(flags);
	}
	else
		ft_config_0(flags);
}
