/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:44:19 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/08 17:18:32 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/*
typedef struct s_stack
{
	int				value;
	int				pos;
	int				index;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
} t_stack;

typedef struct stack
{
	t_stack			*first;
} stack;*/

int			is_overflow(const char *nptr);
int			detect_overflow(int output, int number_length, int index, int sign);

char		*ft_itoa(int n);

int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
void		ft_putstr(char *s);
size_t		ft_strlen(const char *s);

int			check_arguments(char **av);

/*
t_stack		*ft_lstnew(int value, int pos, int index, int target_pos, int cost_a, int cost_b);
stack		*initialize_input_stack(int ac, char **av);
*/

#endif
