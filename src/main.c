/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:10:27 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/08 16:57:41 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
t_stack	*ft_lstnew(int value, int pos, int index, int target_pos, int cost_a, int cost_b)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->pos = pos;
	new->index = index;
	new->target_pos = target_pos;
	new->cost_a = cost_a;
	new->cost_b = cost_b;
	new->next = NULL;
	return (new);
}

stack	*initialize_input_stack(int ac, char **av)
{
	stack	*stack_a;
	t_stack	*element;
	int		i;
	
	stack_a->first = ft_lstnew((int)ft_atolli(av[1]), 0, 0, 0, 0, 0);
	element = stack_a->first;
	i = 1;
	while (av[++i])
		element->next = ft_lstnew((int)ft_atolli(av[i]), 0, 0, 0, 0, 0);
	return (stack_a);
}
*/

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		check_arguments(av);

		if (ac == 3)
		{
			if (ft_atoi(av[1]) > ft_atoi(av[2]))
				ft_putstr("sa\n");
		}
		/*
		if (ac == 4)
		{
			stack	*stack_a;
			
			stack_a = initialize_input_stack(ac, av);

			for (int i = 0; i < ac - 1; i++)
				printf("%d\t", stack_a->value); stack_a = stack_a->next;
		}
		*/
	}
	return (0);
}
