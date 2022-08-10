/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:10:27 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/10 18:02:52 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!check_arguments(av))
			return (0);
		if (ac == 3)
		{
			if (ft_atoi(av[1]) > ft_atoi(av[2]))
				return (ft_putstr_fd("sa\n", 1), 0);
		}
		if (ac > 3)
		{
			t_stack		*a_stack;
			int			*sorted_stack;
			int			i;
			
			sorted_stack = sort_input_stack(ac, av);
			if (!sorted_stack)
				return (0);
			
			a_stack = initialize_stack(ft_atoi(av[1]), find_index(sorted_stack, ft_atoi(av[1])));
			i = 2;
			while (av[i])
			{
				insert_back(a_stack, ft_lstnew(ft_atoi(av[i]), find_index(sorted_stack, ft_atoi(av[i]))));
				i++;
			}
			
			/*
			// DISPLAY CHAINED_LIST SNIPPET
			t_element	*element;
			
			element = a_stack->first;
			for (int p = 0; p < ac - 1; p++) 
			{
				printf("Value=%d\nIndex=%d\n\n", element->value, element->index);
				element = element->next;
			}
			*/

			clear_stack(a_stack);
			free(sorted_stack);
			
		}
	}
	return (0);
}
