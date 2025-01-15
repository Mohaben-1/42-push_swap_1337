/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:42:16 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/13 13:21:59 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->a)
		return ;
	if (list->a && list->tail_a && list->a != list->tail_a)
	{
		tmp = list->tail_a;
		list->tail_a = list->tail_a->prev;
		list->tail_a->next = NULL;
		tmp->prev = NULL;
		tmp->next = list->a;
		list->a->prev = tmp;
		list->a = tmp;
		if (print)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->b)
		return ;
	if (list->b && list->tail_b && list->b != list->tail_b)
	{
		tmp = list->tail_b;
		list->tail_b = list->tail_b->prev;
		list->tail_b->next = NULL;
		tmp->prev = NULL;
		tmp->next = list->b;
		list->b->prev = tmp;
		list->b = tmp;
		if (print)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_list *list, int print)
{
	rra(list, 0);
	rrb(list, 0);
	if (print)
		write(1, "rrr\n", 4);
}
