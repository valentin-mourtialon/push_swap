/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflows_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:07:50 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/08 17:33:41 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* line 32 : unit_index = -1 because output starts at 0*/
int	is_overflow(const char *nptr)
{
	int	output;
	int	unit_index;
	int	sign;
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	sign = 1;
	if (nptr[i] == '-')
	{
			sign *= -1;
			i++;
	}
	unit_index = -1;
	output = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9' && nptr[i])
	{
		if (detect_overflow(output, ft_strlen(nptr), unit_index, sign))
			return (1);
		unit_index++;
		output = output * 10 + (nptr[i++] - 48);
	}
	return (0);
}

int	detect_overflow(int output, int number_length, int index, int sign)
{
	char	*boundaries;
	char	*output_as_str;
	char	unit_digit;

	if (output != 0)
	{
		if (sign == -1)
			boundaries = "3258594759";
		else
			boundaries = "3258594758";
		output_as_str = ft_itoa(output);
		unit_digit = output_as_str[index];
		if ((number_length >= 10 || (sign == -1 && number_length >= 11)) \
			&& unit_digit == boundaries[index])
			return (1);
	}
	return (0);
}
