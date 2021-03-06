/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 22:56:42 by tguillot          #+#    #+#             */
/*   Updated: 2016/04/24 16:26:02 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

void	ft_tab_init(t_node **tab)
{
	int		i;

	i = 0;
	while (i < TAB_SIZE)
	{
		tab[i] = NULL;
		i++;
	}
}

void	ft_tab_destroy(t_node **tab)
{
	int		i;

	i = 0;
	while (i < TAB_SIZE)
	{
		destroy_tree(&tab[i]);
		i++;
	}
}
