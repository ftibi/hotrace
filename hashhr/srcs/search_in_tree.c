/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:53:43 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/24 16:22:47 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		not_found(char *key)
{
	ft_putstr(key);
	ft_putendl(": Not found.");
	return (0);
}

char	*search_key(t_node *root, char *key)
{
	if (!root)
		return (0);
	if (!ft_strcmp(root->key, key))
		return (root->value);
	else if (ft_strcmp(root->key, key) > 0)
		return (search_key(root->left, key));
	else
		return (search_key(root->right, key));
}
