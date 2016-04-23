/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillot <tguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 22:57:15 by tguillot          #+#    #+#             */
/*   Updated: 2016/04/24 00:19:21 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

t_data	*new_maillon(char *data, char *key)
{
	t_data	*ret;

	ret = (t_data*)malloc(sizeof(t_data));
	if (ret)
	{
		ret->data = data;
		ret->key = key;
		ret->next = NULL;
	}
	return (ret);
}

void	add_maillon(t_data **list, t_data *new)
{
	new->next = *list;
	*list = new;
}

void	ft_stock_data(t_data **tab, char *value, char *key)
{
	int		index;

	index = ft_hachage(key);
	add_maillon(&tab[index], new_maillon(value, key));
}
