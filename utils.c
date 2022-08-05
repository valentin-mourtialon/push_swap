/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:34:59 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/05 16:21:57 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	str_to_abs_int(char *number)
{
	unsigned long long	output_number;
	int					i;
	int					c;

	output_number = 0;
	i = 0;
	c = 0;
	while (number[i] == ' ' || (number[i] >= '\t' && number[i] <= '\r'))
		i++;
	while (number[i] == '+' || number[i] == '-')
	{
		if (c > 0)
			return (0);
		i++;
		c++;
	}
	while ('0' <= number[i] && number[i] <= '9' && number[i])
		output_number = output_number * 10 + (number[i++] - 48);
	return (output_number);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	are_equals(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
