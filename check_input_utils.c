/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:28 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/11 14:35:00 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isallspace(char *s)
{
	while (s && *s)
	{
		if (*s != ' ')
			return (0);
		s++;
	}
	return (1);
}

int	ft_str_digit(char *s)
{
	int	flag;

	flag = 0;
	while (s && *s)
	{
		if (!ft_isdigit(*s))
			return (0);
		if (ft_isdigit(*s))
			flag = 1;
		s++;
	}
	if (*s == '\0' && !flag)
		return (0);
	return (1);
}

int	ft_not_valid(char *s)
{
	while (s && *s)
	{
		if (*s != ' ' && *s != '-' && *s != '+' && !ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}

int	ft_check_dup(char **avgs)
{
	int	i;
	int	j;

	i = 0;
	while (avgs[i])
	{
		j = i + 1;
		while (avgs[j])
		{
			if (ft_atoi(avgs[i]) == ft_atoi(avgs[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
