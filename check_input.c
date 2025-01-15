/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:28:25 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/11 18:00:30 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_avgs(int ac, char **av)
{
	int		i;
	int		j;
	int		len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		j = 0;
		if (ft_not_valid(av[i]) || av[i][0] == '\0' || ft_isallspace(av[i]))
			p_error();
		while (av[i][j])
		{
			len++;
			j++;
		}
		len++;
		i++;
	}
	return (len);
}

void	free_avgs(char **avgs)
{
	char	**current;

	if (!avgs)
		return ;
	current = avgs;
	while (*current)
	{
		free(*current);
		current++;
	}
	free(avgs);
}

int	ft_size_avgs(char **avgs)
{
	int	len;

	len = 0;
	while (*avgs != NULL)
	{
		len++;
		avgs++;
	}
	return (len);
}

char	*ft_concat_input(int ac, char **av)
{
	char	*concat;
	int		i;
	int		j;
	int		len;

	i = 1;
	j = 0;
	len = ft_len_avgs(ac, av);
	concat = malloc(len + 1);
	if (concat == NULL)
		p_error();
	while (i < ac)
	{
		while (*av[i]) 
		{
			concat[j] = *av[i];
			(av[i])++;
			j++;
		}
		if (i < ac -1)
			concat[j++] = ' ';
		i++;
	}
	concat[j] = '\0';
	return (concat);
}
