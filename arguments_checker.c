/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:27:01 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/05 16:36:17 by vmourtia         ###   ########.fr       */
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
	unsigned long long	intmax_limit;

	intmax_limit = (unsigned long long)INT_MAX;
	if (number[0] == '-' && str_to_abs_int(number) > intmax_limit + 1)
		return (0);
	else if (str_to_abs_int(number) > intmax_limit)
		return (0);
	else
		return (1);
}

static int	check_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (are_equals(av[i], av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arguments(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!is_number(av[i]))
			return (printf("ERROR NOT A NUMBER\n"), 0);
		if (!is_valid_number(av[i]))
			return (printf("ERROR NOT A VALID NUMBER\n"), 0);
		if (!check_duplicates(av))
			return (printf("ERROR THERE ARE DUPLICATIONS\n"), 0);
	}
	return (1);
}
