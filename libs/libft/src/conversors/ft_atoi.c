/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:03:52 by hbernard          #+#    #+#             */
/*   Updated: 2022/04/22 05:22:48 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ignore(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	while (ft_ignore(*nptr) == 1)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign *= -1;
	while (ft_isdigit(*nptr) == 1)
		number = number * 10 + (*nptr++ - '0');
	return (number * sign);
}
