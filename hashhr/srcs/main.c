/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 20:19:39 by justasze          #+#    #+#             */
/*   Updated: 2016/04/24 16:25:19 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static void	ft_read(t_node **tab)
{
	char	*key;
	char	*value;
	int		a;

	while ((a = get_next_line(0, &key)) > 0)
	{
		if (!ft_strcmp(key, ""))
			return ;
		get_next_line(0, &value);
		ft_stock_data(tab, value, key);
	}
	if (a == -1)
		ft_putendl("Erreur de lecture, fichier mauvais.");
}

int			main(void)
{
	t_node *tab[TAB_SIZE];

	ft_tab_init(tab);
	ft_read(tab);
	ft_search(tab);
	ft_tab_destroy(tab);
	return (0);
}
