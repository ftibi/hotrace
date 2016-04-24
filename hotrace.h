/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:10:41 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/24 15:48:16 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "libft/includes/libft.h"

typedef struct		s_node
{
	struct s_node	*left;
	struct s_node	*right;
	int				depth;
	char			*key;
	char			*value;
}					t_node;

t_node				*new_node(char *key, char *value);
void				add_node(t_node **root, char *key, char *value);
int					search_key(t_node *root, char *key);
int					destroy_tree(t_node **root);
int					destroy_node(t_node **node);

void infix_print_tree(t_node *root);
void prefix_print_tree(t_node *root);
void suffix_print_tree(t_node *root);

t_node *rotate_tree_right(t_node *y);
t_node *rotate_tree_left(t_node *x);

size_t	max(size_t a, size_t b);
size_t		depth(t_node *root);

#endif
