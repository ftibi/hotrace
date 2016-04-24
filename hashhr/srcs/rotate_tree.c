/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 22:52:26 by tbeauman          #+#    #+#             */
/*   Updated: 2016/04/24 15:48:59 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_node	*rotate_tree_right(t_node *y)
{
	t_node	*x;

	x = y->left;
	y->left = x->right;
	x->right = y;
	y->depth = 1 + max(depth(y->left), depth(y->right));
	x->depth = 1 + max(depth(x->left), depth(x->right));
	return (x);
}

t_node	*rotate_tree_left(t_node *x)
{
	t_node	*y;

	y = x->right;
	x->right = y->left;
	y->left = x;
	y->depth = 1 + max(depth(y->left), depth(y->right));
	x->depth = 1 + max(depth(x->left), depth(x->right));
	return (y);
}

// t_node *rotate_tree_right(t_node *y)
// {
// 	t_node	*x;
//
// 	x = y->left;
// 	if (!x)
// 		return ;
// 	y->left = x->right;
// 	if (x->right)
// 		x->right->parent = y;
// 	x->parent = y->parent;
// 	if (!y->parent)
// 		; // Need to set the root of our tree at x
// 	else if (y == y->parent->left)
// 		y->parent->left = x;
// 	else
// 		y->parent->right = x;
// 	x->right = y;
// 	y->parent = x;
// }
//
// t_node *rotate_tree_left(t_node *x)
// {
// 	t_node	*y;
//
// 	y = x->right;
// 	if (!y)
// 		return ;
// 	x->right = y->left;
// 	if (y->left)
// 		y->left->parent = x;
// 	y->parent = x->parent;
// 	if (!x->parent)
// 		; // Need to set the root of our tree at y
// 	else if (x == x->parent->left)
// 		x->parent->left = y;
// 	else
// 		x->parent->right = y;
// 	y->left = x;
// 	x->parent = y;
// }
