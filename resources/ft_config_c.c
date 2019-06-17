/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:12:29 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 14:14:13 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_flag_minus(t_flags *flags)
{
	ft_config_8(flags);
}

void			ft_flag_prior_c(t_flags *flags)
{
	if (flags->flag[0])
	{
		if (flags->flag[0] == 2)
			ft_flag_minus(flags);
		else
			ft_config_7(flags);
	}
	else
		ft_config_7(flags);
}
