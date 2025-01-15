/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:49:06 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/13 11:20:58 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->b)
		return ;
	if (list->size_b >= 1)
	{
		tmp = list->b;
		list->b = list->b->next;
		if (list->b)
			list->b->prev = NULL;
		tmp->next = list->a;
		if (list->a)
			list->a->prev = tmp;
		list->a = tmp;
		list->size_a++;
		list->size_b--;
		list->tail_a = ft_lstlast(list->a);
		list->tail_b = ft_lstlast(list->b);
		if (print)
			write(1, "pa\n", 3);
	}
}

void	pb(t_list *list, int print)
{
	t_stack	*tmp;

	if (!list->a)
		return ;
	if (list->size_a >= 1)
	{
		tmp = list->a;
		list->a = list->a->next;
		if (list->a)
			list->a->prev = NULL;
		tmp->next = list->b;
		if (list->b)
			list->b->prev = tmp;
		list->b = tmp;
		list->size_b++;
		list->size_a--;
		list->tail_b = ft_lstlast(list->b);
		list->tail_a = ft_lstlast(list->a);
		if (print)
			write(1, "pb\n", 3);
	}
}
