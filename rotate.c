/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:35:57 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/13 11:21:42 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->a)
		return ;
	if (list->a && list->a->next && list->tail_a)
	{
		tmp = list->a;
		list->a = list->a->next;
		list->a->prev = NULL;
		list->tail_a->next = tmp;
		tmp->prev = list->tail_a;
		tmp->next = NULL;
		list->tail_a = tmp;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rb(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->b)
		return ;
	if (list->b && list->b->next && list->tail_b)
	{
		tmp = list->b;
		list->b = list->b->next;
		list->b->prev = NULL;
		list->tail_b->next = tmp;
		tmp->prev = list->tail_b;
		tmp->next = NULL;
		list->tail_b = tmp;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rr(t_list *list, int print)
{
	ra(list, 0);
	rb(list, 0);
	if (print)
		write(1, "rr\n", 3);
}
