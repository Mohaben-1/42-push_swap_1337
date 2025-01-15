/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:13:41 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/13 15:46:53 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] || !s1[i] || !s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	exec_move(t_list *list, char *move)
{
	if (!ft_strncmp(move, "sa\n", 3))
		sa(list, 0);
	else if (!ft_strncmp(move, "sb\n", 3))
		sb(list, 0);
	else if (!ft_strncmp(move, "ss\n", 3))
		ss(list, 0);
	else if (!ft_strncmp(move, "pa\n", 3))
		pa(list, 0);
	else if (!ft_strncmp(move, "pb\n", 3))
		pb(list, 0);
	else if (!ft_strncmp(move, "ra\n", 3))
		ra(list, 0);
	else if (!ft_strncmp(move, "rb\n", 3))
		rb(list, 0);
	else if (!ft_strncmp(move, "rr\n", 3))
		rr(list, 0);
	else if (!ft_strncmp(move, "rra\n", 4))
		rra(list, 0);
	else if (!ft_strncmp(move, "rrb\n", 4))
		rrb(list, 0);
	else if (!ft_strncmp(move, "rrr\n", 4))
		rrr(list, 0);
	else
		p_error();
}
