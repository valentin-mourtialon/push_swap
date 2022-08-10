/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:04:06 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/10 18:02:31 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	*sort_input_stack(int ac, char **av)
{
	int	*tab;
	int	i;
	int	j;

	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (av[++i])
		tab[i - 1] = ft_atoi(av[i]);
	i = 0;
	while (i < ac - 2)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	return (tab);
}

int	find_index(int *sorted_tab, int number)
{
	int	i;

	i = 0;
	while (sorted_tab[i] != number)
		i++;
	return (i + 1);
}
