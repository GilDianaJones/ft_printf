/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_configs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:10:45 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 13:08:16 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_config_9(t_flags *flags)
{
	ft_width_prec_str(flags);
	ft_width_display_str(flags);
	ft_display_str(flags);
}

void		ft_config_10(t_flags *flags)
{
	ft_display_str(flags);
	ft_width_prec_str(flags);
	ft_width_display_str(flags);
}
