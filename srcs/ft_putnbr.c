/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:18:00 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 12:41:28 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(intmax_t n)
{
	intmax_t	nbr;

	nbr = 0;
	if (n < 0)
	{
		nbr = n * -1;
		ft_putchar('-');
	}
	if (n > 0)
		nbr = n;
	if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
}
