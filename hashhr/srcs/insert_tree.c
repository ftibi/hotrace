/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:39:57 by tbeauman          #+#    #+#             */
/*   Updated: 2016/04/24 15:48:44 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_node	*new_node(char *key, char *value)
{
	t_node	*new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return (0);
	new->left = 0;
	new->right = 0;
	new->depth = 1;
	new->key = key;//ft_strdup(key);
	new->value = value;//ft_strdup(value);
	return (new);
}

t_node	*balance_tree(t_node *x)
{
	int		eq;

	eq = depth(x->left) - depth(x->right);
	if (eq > 1)
	{
		if (depth(x->left->right) > depth(x->left->left))
			x->left = rotate_tree_left(x->left);
		return (rotate_tree_right(x));
	}
	else if (eq < -1)
	{
		if (depth(x->right->left) > depth(x->right->right))
			x->right = rotate_tree_right(x->right);
		return (rotate_tree_left(x));
	}
	return (x);
}

void	add_node(t_node **root, char *key, char *value)
{
	int		strcmp;

	if (!(*root) && (*root = new_node(key, value)))
		return ;
	else if ((strcmp = ft_strcmp(key, (*root)->key)) < 0)
		add_node(&(*root)->left, key, value);
	else if (!strcmp)
	{
		free((*root)->value);
		(*root)->value = value;
		return ;
	}
	else
		add_node(&(*root)->right, key, value);
	(*root)->depth = max(depth((*root)->left), depth((*root)->right)) + 1;
	*root = balance_tree(*root);
}
