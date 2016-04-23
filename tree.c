/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:53:43 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/23 15:24:53 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_node		*add_node(t_node *root, char *key, char *value)
{
	if (!root)
		return (new_node(0, key, value));
	if (ft_strcmp(root->key, key) < 0)
	{
		if (root->left)
			return (add_node(root->left, key, value));
		else
		{
			root->left = new_node(root, key, value);
			return (root->left);
		}
	}
	else
	{
		if (root->right)
			return (add_node(root->right, key, value));
		else
		{
			root->right = new_node(root, key, value);
			return (root->right);
		}
	}
}

int		not_found(char *key)
{
	ft_putstr(key);
	ft_putendl(" : Not found.");
	return (0);
}

int		search_key(t_node *root, char *key)
{
	if (!root)
		return (0);
	if (!(ft_strcmp(root->key, key)))
	{
		ft_putstr(key);
		ft_putstr(" : ");
		ft_putendl(root->value);
		return (0);
	}
	else if (ft_strcmp(root->key, key) < 0)
	{
		if (root->left)
			return (search_key(root->left, key));
		else
			return (not_found(key));
	}
	else //if (ft_strcmp(root->key, key) > 0)
	{
		if (root->right)
			return (search_key(root->right, key));
		else
			return (not_found(key));
	}
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
	if (tmp->parent)
	{
		if (tmp->parent->left == tmp)
			tmp->parent->left = 0;
		else if (tmp->parent->right == tmp)
			tmp->parent->right = 0;
	}
	destroy_node(&tmp);
	return (0);
}









