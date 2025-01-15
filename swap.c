/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:56:20 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/13 11:22:03 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s1, t_stack *s2)
{
	int	tmp;

	tmp = s1->data;
	s1->data = s2->data;
	s2->data = tmp;
	tmp = s1->index;
	s1->index = s2->index;
	s2->index = tmp;
}

void	sa(t_list *list, int print)
{
	if (!list->a)
		return ;
	if (list->size_a >= 2)
	{
		swap(list->a, list->a->next);
		list->tail_a = ft_lstlast(list->a);
		if (print)
			write(1, "sa\n", 3);
	}
}

void	sb(t_list *list, int print)
{
	if (!list->b)
		return ;
	if (list->size_b >= 2)
	{
		swap(list->b, list->b->next);
		list->tail_b = ft_lstlast(list->b);
		if (print)
			write(1, "sb\n", 3);
	}
}

void	ss(t_list *list, int print)
{
	sa(list, 0);
	sb(list, 0);
	if (print)
		write(1, "ss\n", 3);
}
