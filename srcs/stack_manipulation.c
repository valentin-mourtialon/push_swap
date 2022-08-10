/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:22:26 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/10 17:36:48 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <push_swap.h>

// int *element_data
t_element	*ft_lstnew(int value, int index)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = index;
	new->next = NULL;
	return (new);
}

/*
new->pos = element_data[0];
new->target_pos = element_data[2];
new->cost_a = element_data[3];
new->cost_b = element_data[4];
*/
	
t_stack	*initialize_stack(int arg, int index)
{
	t_stack		*stack;
	t_element	*element;
	
	stack = malloc(sizeof(t_stack));
	element = ft_lstnew(arg, index);
	if (!stack || !element)
		return (NULL);
	stack->first = element;
	return (stack);
}

t_element	*ft_get_last_element(t_stack *stack)
{
	t_element	*element;

	if (!stack)
		return (NULL);
	element = stack->first;
	while (element->next != NULL)
		element = element->next;
	return (element);
}

void	insert_back(t_stack *stack, t_element *new_element)
{
	t_element	*last_element;

	if (stack != NULL || new_element != NULL)
	{
		last_element = ft_get_last_element(stack);
		last_element->next = new_element;
	}
}

void	clear_stack(t_stack *stack)
{
	t_element	*element;
	t_element	*temp;

	if (stack != NULL)
	{
		element = stack->first;
		free(stack);
		while (element->next != NULL)
		{
			temp = element->next;
			free(element);
			element = temp;
		}
		free(element);
	}
}