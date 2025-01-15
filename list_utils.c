/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:21:39 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/13 14:32:01 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->data = data;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_lstadd_back(t_list *list, t_stack *new)
{
	t_stack	*current;

	if (!list || !new)
		return ;
	if (!list->a)
		list->a = new;
	else
	{
		current = list->a;
		while (current)
		{
			if (current->data > new->data)
				current->index++;
			else
				new->index++;
			if (!current->next)
				break ;
			current = current->next;
		}
		current->next = new;
		new->prev = current;
	}
	list->tail_a = new;
	list->size_a++;
}

void	ft_lst_free(t_list *list)
{
	t_stack	*tmp;

	if (list->a)
	{
		while (list->a)
		{
			tmp = list->a;
			list->a = list->a->next;
			free(tmp);
		}
	}
}

void	ft_stack_init(t_list	*list, char **avgs)
{
	int		i;
	long	data;

	list->a = NULL;
	list->b = NULL;
	list->size_a = 0;
	list->size_b = 0;
	i = 0;
	while (i < ft_size_avgs(avgs))
	{
		data = ft_atoi(avgs[i]);
		if (data == LONG_MAX)
		{
			free_avgs(avgs);
			ft_lst_free(list);
			p_error();
		}
		ft_lstadd_back(list, ft_lstnew(ft_atoi(avgs[i])));
		i++;
	}
}
