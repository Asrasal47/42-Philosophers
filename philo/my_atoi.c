/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:56:43 by arasal            #+#    #+#             */
/*   Updated: 2022/12/09 16:18:32 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_int(int sign, int *n)
{
	if (!sign && *n == INT_MIN)
		return (2);
	if (*n < 0 && *n != INT_MIN)
		return (2);
	return (0);
}

int	my_atoi(const char *str, int *n)
{
	int	sign;

	sign = 0;
	*n = 0;
	if (*str == '-')
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str < '0' && *str > '9')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		*n *= 10;
		*n += *str - '0';
		if (check_int(sign, n))
			return (2);
		str++;
	}
	if (sign)
		*n *= -1;
	if (*str == '\0')
		return (0);
	return (1);
}
