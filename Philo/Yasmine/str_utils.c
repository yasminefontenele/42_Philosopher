/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:57:37 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/27 07:20:07 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_intlen(int num)
{
	int	i;

	i = 0;
	if(num <= 0)
		i++;
	while(num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void ft_str_reverse(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	unsigned int	nbr_temp;
	int		i;

	i = 0;
	str = malloc(sizeof(char *) * (ft_intlen(nbr) + 1) );
	if(!str)
		return (NULL);
	if(nbr < 0)
		nbr_temp = nbr * -1;
	else
		nbr_temp = nbr;
	while(nbr_temp)
	{
		str[i++] = (nbr_temp % 10) + '0';
		nbr_temp /= 10;
	}
	if(nbr == 0)
		str[i++] = '0';
	if(nbr < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_str_reverse(str);
	return (str);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		signal;
	long	result;

	i = 0;
	result = 0;
	signal = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		signal = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if (result > 922337203685477580 || (result == 922337203685477580
				&& ((!signal && str[i] - '0' > 7) || (signal && str[i] - '0' > 8))))
			return (-1 * !signal);
		else
			result = (result * 10) + str[i++] - '0';
	}
	if (signal)
		result = -result;
	return (result);
}