/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:38:15 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/13 15:22:28 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list *list)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = list->a->index;
	n2 = list->a->next->index;
	n3 = list->a->next->next->index;
	if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		sa(list, 1);
		rra(list, 1);
	}
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		ra(list, 1);
	else if (n1 < n2 && n1 > n3 && n2 > n3)
		rra(list, 1);
	else if (n1 > n2 && n1 < n3 && n2 < n3)
		sa(list, 1);
	else if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		sa(list, 1);
		ra(list, 1);
	}
}

void	push_min_sort4_5(t_list *list, int pos, int len_stack)
{
	if (pos <= 1)
	{
		if (pos == 1)
			sa(list, 1);
		pb(list, 1);
		return ;
	}
	if (pos <= len_stack / 2)
	{
		while (pos-- > 0)
			ra(list, 1);
	}
	else
	{
		while (pos++ < len_stack)
			rra(list, 1);
	}
	pb(list, 1);
}

void	sort_4_5(t_list *list)
{
	t_stack	*current;
	int		pos;
	int		i;

	i = 0;
	while (i <= list->size_a - 3)
	{
		current = list->a;
		pos = 0;
		while (current)
		{
			if (current->index == i)
			{
				push_min_sort4_5(list, pos, list->size_a);
				break ;
			}
			pos++;
			current = current->next;
		}
		i++;
	}
	sort_3(list);
	pa(list, 1);
	pa(list, 1);
}

int	ft_check_sorted(t_stack *a)
{
	t_stack	*current;

	current = a;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_stack(t_list *list)
{
	int	range_min;
	int	range_max;

	if (!list)
		return ;
	range_min = 0;
	range_max = list->size_a * 0.048 + 10;
	if (list->size_a == 2)
	{
		if (list->a->index > list->a->next->index)
			sa(list, 1);
	}
	else if (list->size_a == 3)
		sort_3(list);
	else if (list->size_a <= 5)
		sort_4_5(list);
	else
		sort_range(list, range_min, range_max);
}
