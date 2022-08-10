/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:10:27 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/10 16:29:58 by vmourtia         ###   ########.fr       */
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
		if (ac == 4)
		{
			t_stack		*a_stack;
			t_element	*element;
			int		i;
			
			a_stack = initialize_stack(ft_atoi(av[1]));
			i = 2;
			while (av[i])
				insert_back(a_stack, ft_lstnew(ft_atoi(av[i++])));

			// DISPLAY CHAINED_LIST SNIPPET
			element = a_stack->first;
			for (int i = 0; i < ac - 1; i++) {
				printf("%d\n", element->value); element = element->next;
			}

			clear_stack(a_stack);
		}
	}
	return (0);
}
