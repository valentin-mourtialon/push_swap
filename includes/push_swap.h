/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:44:19 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/10 16:24:16 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_element
{
	int					value;
	/*int					pos;
	int					index;
	int					target_pos;
	int					cost_a;
	int					cost_b;*/
	struct s_element	*next;
} t_element;

typedef struct s_stack
{
	t_element		*first;
} t_stack;

// srcs
long		ft_atoi(char *arg);
int			check_arguments(char **av);

// utils
char		*ft_itoa(int n);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);

// stack_manipulation
t_element	*ft_lstnew(int value);/*, int pos, int index, int target_pos, int cost_a, int cost_b);*/
t_stack		*initialize_stack(int arg);
t_element	*ft_get_last_element(t_stack *stack);
void		insert_back(t_stack *stack, t_element *new_element);
void		clear_stack(t_stack *stack);

#endif
