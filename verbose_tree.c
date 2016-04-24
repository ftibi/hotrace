/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 20:09:48 by tbeauman          #+#    #+#             */
/*   Updated: 2016/04/23 20:16:41 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void infix_print_tree(t_node *root)
{
	if (!root)
		return ;
	if (root->left)
		infix_print_tree(root->left);
	ft_putstr(root->key);
	ft_putstr(" => ");
	ft_putendl(root->value);
	if (!root->left && !root->right)
		ft_putendl("-> it's a leaf\n");
	if (root->right)
		infix_print_tree(root->right);
}

void prefix_print_tree(t_node *root)
{
	if (!root)
		return ;
	ft_putstr(root->key);
	ft_putstr(" => ");
	ft_putendl(root->value);
	if (!root->left && !root->right)
		ft_putendl("-> it's a leaf\n");
	if (root->left)
		prefix_print_tree(root->left);
	if (root->right)
		prefix_print_tree(root->right);
}

void suffix_print_tree(t_node *root)
{
	if (!root)
		return ;
	if (root->left)
		suffix_print_tree(root->left);
	if (root->right)
		suffix_print_tree(root->right);
	ft_putstr(root->key);
	ft_putstr(" => ");
	ft_putendl(root->value);
	if (!root->left && !root->right)
		ft_putendl("-> it's a leaf\n");
}
