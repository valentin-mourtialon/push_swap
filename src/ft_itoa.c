/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:42:22 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/08 17:34:13 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	count_digits(long int p)
{
	int		nb_of_digits;

	if (p < 0)
		p *= -1;
	nb_of_digits = 0;
	while (p > 9)
	{
		nb_of_digits++;
		p /= 10;
	}
	nb_of_digits++;
	return (nb_of_digits);
}

static int	compute_ten_power(int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (10);
	return (10 * compute_ten_power(power - 1));
}

static char	*alloc_space_for_digits(long int p, int nb_of_digits)
{
	char	*nbr;

	if (p < 0)
		nb_of_digits++;
	nbr = malloc((nb_of_digits + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	return (nbr);
}

static void	check_negative_numbers(long int *p, int *i, int *shift, char **nbr)
{
	if (*p < 0)
	{
		(*nbr)[(*i)++] = '-';
		(*shift)++;
		*p *= -1;
	}
}

char	*ft_itoa(int n)
{
	int			nb_of_digits;
	int			i;
	int			shift;
	long int	p;
	char		*nbr;

	p = (long int)n;
	nb_of_digits = count_digits(p);
	nbr = alloc_space_for_digits(p, nb_of_digits);
	if (!nbr)
		return (NULL);
	i = 0;
	shift = 0;
	check_negative_numbers(&p, &i, &shift, &nbr);
	while (i < nb_of_digits + shift)
	{
		nbr[i] = p / compute_ten_power(nb_of_digits - (i + 1 - shift)) + '0';
		p %= compute_ten_power(nb_of_digits - (i++ + 1 - shift));
	}
	nbr[i] = '\0';
	return (nbr);
}
