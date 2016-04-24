/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:10:41 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/24 16:42:53 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 10000

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



int					get_next_line(int const fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(char const *s1);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlen(char const *str);
void				ft_putstr(char const *str);
char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memalloc(size_t size);

#endif
