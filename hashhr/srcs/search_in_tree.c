/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:53:43 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/23 20:15:15 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		not_found(char *key)
{
	ft_putstr(key);
	ft_putendl(": Not found.");
	return (0);
}

int		search_key(t_node *root, char *key)
{
	if (!root)
		return (0);
	if (!(ft_strcmp(root->key, key)))
	{
		ft_putendl(root->value);
		return (0);
	}
	else if (ft_strcmp(root->key, key) > 0)
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
