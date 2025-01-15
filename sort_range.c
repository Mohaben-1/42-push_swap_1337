/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:43:36 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/14 12:30:27 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int		max;

	if (!stack)
		return (-1);
	max = INT_MIN;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	find_pos_max(t_stack *stack)
{
	int		max;
	int		pos;

	max = find_max(stack);
	pos = 0;
	while (stack)
	{
		if (stack->data == max)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	push_to_a_sorted(t_list *list)
{
	int	mid;
	int	pos;
	int	max;

	while (list->b)
	{
		mid = list->size_b / 2;
		max = find_max(list->b);
		pos = find_pos_max(list->b);
		if (pos <= mid)
		{
			while (list->b && list->b->data != max)
				rb(list, 1);
		}
		else
		{
			while (list->b && list->b->data != max)
				rrb(list, 1);
		}
		pa(list, 1);
	}
}

void	sort_range(t_list *list, int range_min, int range_max)
{
	t_stack	*next;

	while (list->a)
	{
		next = list->a->next;
		if (list->a->index >= range_min && list->a->index <= range_max)
		{
			pb(list, 1);
			range_min++;
			range_max++;
		}
		else if (list->a->index > range_max)
			ra(list, 1);
		else if (list->a->index < range_min)
		{
			pb(list, 1);
			rb(list, 1);
			range_min++;
			range_max++;
		}
		list->a = next;
	}
	push_to_a_sorted(list);
}
