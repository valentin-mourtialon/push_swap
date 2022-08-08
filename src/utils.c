/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:34:59 by vmourtia          #+#    #+#             */
/*   Updated: 2022/08/08 17:14:31 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ft_atoi(const char *nptr)
{
	int	output;
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
	output = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9' && nptr[i])
		output = output * 10 + (nptr[i++] - 48);
	return (sign * output);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			write(1, &(s[i++]), 1);
	}
}
