/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:31:57 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 16:14:15 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_flags_init(t_flags *flags)
{
	flags->flag[0] = 0;
	flags->len = 0;
	flags->width = 0;
	flags->prec = 0;
	flags->spec = 24;
	flags->prec_orig = 0;
	flags->width_orig = 0;
	flags->c = 0;
	flags->str = NULL;
	flags->wstr = 0;
}

void			ft_spec_is_ok(int *i, t_flags *flags, char *fmt, va_list ap)
{
	int			j;

	j = 0;
	while ((flags->flag[j] = ft_flags(i, fmt)) != 0)
		j++;
	flags->width = ft_width(i, fmt);
	flags->width_orig = flags->width;
	if (flags->width_orig == -1)
		flags->width = va_arg(ap, unsigned int);
	flags->prec = ft_precision(i, fmt);
	flags->prec_orig = flags->prec;
	if (flags->prec_orig == -1)
		flags->prec = va_arg(ap, unsigned int);
	flags->len = ft_length(i, fmt);
	flags->spec = ft_specifiers(fmt[*i]);
}

void			ft_flags_order(int *i, char *fmt, t_flags *flags, va_list ap)
{
	int j;
	int k;

	j = *i;
	k = 0;
	while ((ft_flags(&j, fmt) > 0 || ft_width(&j, fmt) > 0 ||
			ft_precision(&j, fmt) > 0 || ft_length(&j, fmt) > 0))
		;
	if (!fmt[j] || (flags->spec = ft_specifiers(fmt[j])) == 24)
	{
		flags->spec = 24;
		while ((flags->flag[k] = ft_flags(i, fmt)) != 0)
			k++;
		flags->width = ft_width(i, fmt);
		*i = j - 1;
		return ;
	}
	ft_spec_is_ok(i, flags, fmt, ap);
}
