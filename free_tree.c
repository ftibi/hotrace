/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:40:12 by tbeauman          #+#    #+#             */
/*   Updated: 2016/04/24 16:56:21 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

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

int		destroy_tree(t_node **root)
{
	t_node	*tmp;

	if (!root || !(*root))
		return (0);
	tmp = *root;
	if (tmp->left)
		destroy_tree(&tmp->left);
	if (tmp->right)
		destroy_tree(&tmp->right);
	destroy_node(&tmp);
	return (0);
}
