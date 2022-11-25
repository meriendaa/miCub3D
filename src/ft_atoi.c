/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:10:13 by amantara          #+#    #+#             */
/*   Updated: 2022/11/19 11:25:41 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	validate_char(char c)
{
	if (c == ' ' || c == '\t'
		|| c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
	{
		return (1);
	}
	return (0);
}

int	max_long(long int sum, int signo)
{
	if (sum * signo > 2147483647)
		return (-1);
	else if (sum * signo < -2147483648)
		return (0);
	return (1);
}

int	ft_atoi(const char *str1)
{
	int			i;
	int			signo;
	long int	sum;
	char		*str;

	str = (char *) str1;
	sum = 0;
	i = 0;
	signo = 1;
	while (validate_char(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (max_long(sum, signo) == -1 || max_long(sum, signo) == 0)
			return (max_long(sum, signo));
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (sum * signo);
}
