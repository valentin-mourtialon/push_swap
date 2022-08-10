/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:27:01 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/10 15:28:45 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* "is_number" also check huge overflows : 11 digits and more */
static bool	is_number(char *arg, int *sign, int *i)
{
	int	j;

	if (arg[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	j = *i;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]))
			return (false);
		j++;
	}
	if ((*sign == -1 && j > 11) || (*sign == 1 && j > 10))
		return (printf("ERROR OVERFLOW!\nMORE THAN 10 digits!\tsign=%d\tj=%d\n", *sign, j), false);
	return (true);
}

/* LONG_MAX is used as an error code */
long	ft_atoi(char *arg)
{
	long	output;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (!is_number(arg, &sign, &i))
		return (printf("NOT A NUMBER!"), LONG_MAX);
	output = 0;
	while ('0' <= arg[i] && arg[i] <= '9' && arg[i])
		output = output * 10 + (arg[i++] - 48);
	if (sign * output > (long)INT_MAX || sign * output < (long)INT_MIN)
		return (printf("ERROR OVERFLOW!"), LONG_MAX);
	return (sign * output);
}

/* We add the condition i == 1 because we only want to check once if there's an error with the number */
static bool	any_duplication(char **av, bool *is_already_sorted)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		if (i == 1 && ft_atoi(av[i]) == LONG_MAX)
			return (true);
		j = i + 1;
		while (av[j])
		{
			if (i == 1 && ft_atoi(av[j]) == LONG_MAX)
				return (true);
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (printf("ERROR THERE ARE DUPLICATIONS!\n"), true);
			if (*is_already_sorted && ft_atoi(av[i]) > ft_atoi(av[j]))
				*is_already_sorted = false;
			j++;
		}
	}
	return (false);
}

int	check_arguments(char **av)
{
	bool	is_already_sorted;

	is_already_sorted = true;
	if (any_duplication(av, &is_already_sorted))
		return (0);
	if (is_already_sorted)
		return(printf("THE STACK IS ALREADY SORTED\n"), 0);
	return (1);
}
