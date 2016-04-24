/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:39:57 by tbeauman          #+#    #+#             */
/*   Updated: 2016/04/24 02:14:00 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_node	*new_node(t_node *parent, char *key, char *value)
{
	t_node	*new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return (0);
	new->parent = parent;
	new->left = 0;
	new->right = 0;
	new->depth = 1;
	new->key = key;//ft_strdup(key);
	new->value = value;//ft_strdup(value);
	return (new);
}

void		add_node(t_node *daddy, t_node **root, char *key, char *value)
{
	int		strcmp;

	if (!(*root) && (*root = new_node(daddy, key, value)))
		return ;
	else if ((strcmp = ft_strcmp(key, (*root)->key)) < 0)
		add_node(*root, &(*root)->left, key, value);
	else if (!strcmp)
	{
		free((*root)->value);
		(*root)->value = value;
		return ;
	}
	else
		add_node(*root, &(*root)->right, key, value);
	(*root)->depth = max(depth((*root)->left), depth((*root)->right)) + 1;
	int eq;
	eq = *root ? depth((*root)->left) - depth((*root)->right) : 0;
	if (eq > 1 && ft_strcmp(key, (*root)->left->key) < 0)
		rotate_tree_right(root);
	else if (eq < -1 && ft_strcmp(key, (*root)->right->key) > 0)
		rotate_tree_left(root);
	else if (eq > 1 && ft_strcmp(key, (*root)->left->key) > 0)
	{
		rotate_tree_left(&(*root)->left);
		rotate_tree_right(root);
	}
	else if (eq < -1 && ft_strcmp(key, (*root)->right->key) < 0)
	{
		rotate_tree_right(&(*root)->right);
		rotate_tree_left(root);
	}
}
