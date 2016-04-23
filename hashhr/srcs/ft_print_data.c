/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillot <tguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 22:57:42 by tguillot          #+#    #+#             */
/*   Updated: 2016/04/24 00:23:19 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

void	print_data(t_data **tab)
{
	int		i;
	t_data	*elem;

	i = -1;
	while (++i < TAB_SIZE)
	{
		if (tab[i]->data != NULL)
		{
			elem = tab[i];
			while (elem != NULL)
			{
				ft_putendl(elem->data);
				elem = elem->next;
			}
		}
	}
}
