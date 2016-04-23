/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillot <tguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 16:24:06 by tguillot          #+#    #+#             */
/*   Updated: 2016/04/23 12:56:57 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static int	ft_val(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void		ft_putnbr(int n)
{
	int j;
	int i;
	int power;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	i = 0;
	j = 0;
	if (n < 0)
	{
		ft_putchar('-');
		i++;
		n = n * (-1);
	}
	while (j < ft_val(n))
	{
		power = ft_val(n) - j - 1;
		ft_putchar(48 + (n / (ft_iterative_power(10, power)) % 10));
		j++;
	}
}
