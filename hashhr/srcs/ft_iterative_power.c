/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillot <tguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 16:16:25 by tguillot          #+#    #+#             */
/*   Updated: 2016/04/23 13:08:35 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

int	ft_iterative_power(int nb, int power)
{
	int pow;
	int result;

	pow = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb;
	while (pow < power)
	{
		result = result * nb;
		pow++;
	}
	return (result);
}
