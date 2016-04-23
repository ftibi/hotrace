/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:13:46 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/23 12:09:52 by tfolly           ###   ########.fr       */
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
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	return (new);
}

void	destroy_node(t_node *node)
{
	if (node)
	{
		if (node->key)
			ft_memdel((void**)&(node->key));
		if (node->value)
			ft_memdel((void**)&(node->value));
		ft_memdel((void**)&node);
	}
}
