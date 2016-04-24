/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 22:52:26 by tbeauman          #+#    #+#             */
/*   Updated: 2016/04/24 02:29:48 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void rotate_tree_right(t_node **y)
{
	t_node	*x;

	x = (*y)->left;
	if (!x)
		return ;
	(*y)->left = x->right;
	if (x->right)
		x->right->parent = *y;
	x->parent = (*y)->parent;
	if (!(*y)->parent)
		; // Need to set the root of our tree at x
	else if (*y == (*y)->parent->left)
		(*y)->parent->left = x;
	else
		(*y)->parent->right = x;
	x->right = *y;
	(*y)->parent = x;
}

void rotate_tree_left(t_node **x)
{
	t_node	*y;

	y = (*x)->right;
	if (!y)
		return ;
	(*x)->right = y->left;
	if (y->left)
		y->left->parent = *x;
	y->parent = (*x)->parent;
	if (!(*x)->parent)
		; // Need to set the root of our tree at y
	else if (*x == (*x)->parent->left)
		(*x)->parent->left = y;
	else
		(*x)->parent->right = y;
	y->left = *x;
	(*x)->parent = y;
}
