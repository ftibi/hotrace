/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:13:46 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/23 15:26:08 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_node	*new_node(t_node *parent, char *key, char *value)
{
	t_node	*new;

	if (!(new = (t_node*)ft_memalloc(sizeof(t_node))))
		return (0);
	new->parent = parent;
	new->left = 0;
	new->right = 0;
	if (parent && parent->color)
		new->color = 0;
	else
		new->color = 1;
	new->key = key;//ft_strdup(key);
	new->value = value;//ft_strdup(value);
	return (new);
}


int		destroy_node(t_node **node2)
{
	t_node	*node;

	if (node2 && *node2)
		node = *node2;
	else
		return (0);
	if (node)
	{
		if (node->key)
			ft_strdel(&(node->key));
		if (node->value)
			ft_strdel(&(node->value));
		ft_memdel((void**)&node);
	}
	return (0);
}
