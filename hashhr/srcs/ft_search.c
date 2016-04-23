/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillot <tguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:07:50 by tguillot          #+#    #+#             */
/*   Updated: 2016/04/24 00:24:54 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

char	*solve_collisions(t_data *cols, char *key)
{
	while (cols)
	{
		if (!ft_strcmp(cols->key, key))
			return (cols->data);
		cols = cols->next;
	}
	return (NULL);
}

void	ft_search(t_data **tab)
{
	char	*line;
	char	*found;
	int		a;
	int		nbr;

	a = 0;
	while ((a = get_next_line(0, &line)) > 0)
	{
		if (ft_strcmp(line, "") == 0)
			return ;
		nbr = ft_hachage(line);
		found = solve_collisions(tab[nbr], line);
		if (found)
			ft_putendl(found);
		else
		{
			ft_putstr(line);
			ft_putendl(": Not found.");
		}
	}
	if (a == -1)
		ft_putendl("\033[31mErreur de lecture, fichier mauvais.\033[0m");
}
