/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:27:01 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/08 17:16:41 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	is_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_number(char *number)
{
	if ((number[0] == '-' && ft_strlen(number) > 11) || ft_strlen(number) > 10)
		return (printf("OVERFLOW\n"), 0);
	if (is_overflow(number))
		return (printf("OVERFLOW\n"), 0);
	return (printf("NO OVERFLOW\n"), 1);
}

static int	check_duplicates(char **av, int *is_already_sorted)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			if (*is_already_sorted == 1 && ft_atoi(av[i]) > ft_atoi(av[j]))
				*is_already_sorted = 0;
			j++;
		}
	}
	return (1);
}

static int	check_numbers_validity(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!is_number(av[i]))
			return (printf("ERROR NOT A NUMBER OR SIGN ERROR\n"), 0);
		if (!is_valid_number(av[i]))
			return (printf("ERROR NOT A VALID NUMBER\n"), 0);
	}
	return (1);
}

int	check_arguments(char **av)
{
	int	is_already_sorted;

	if (!check_numbers_validity(av))
		return (0);
	is_already_sorted = 1;
	if (!check_duplicates(av, &is_already_sorted))
		return (printf("ERROR THERE ARE DUPLICATIONS\n"), 0);
	if (is_already_sorted)
		printf("THE STACK IS ALREADY SORTED\n");
	return (1);
}
