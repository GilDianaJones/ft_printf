/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:19:25 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 15:41:50 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_width_backup(t_flags *flags)
{
	if (flags->spec == 3 || flags->spec == 4 || flags->spec == 5)
	{
		if (flags->tmp == 0 && flags->prec_orig == 0)
			flags->width = flags->width_orig;
	}
	else if (flags->spec == 2 || flags->spec == 6 || flags->spec == 7 ||
			flags->spec == 8 || flags->spec == 9 || flags->spec == 10 ||
			flags->spec == 11)
	{
		if (flags->utmp == 0 && flags->prec_orig == 0)
			flags->width = flags->width_orig;
	}
}
