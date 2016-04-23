/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 20:19:39 by justasze          #+#    #+#             */
/*   Updated: 2016/04/24 00:25:22 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static void	ft_read(t_data **tab)
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
		ft_putendl("\033[31mErreur de lecture, fichier mauvais.\033[0m");
}

int			main(void)
{
	t_data *tab[TAB_SIZE];

	ft_tab_init(tab);
	ft_read(tab);
	ft_search(tab);
	return (0);
}
