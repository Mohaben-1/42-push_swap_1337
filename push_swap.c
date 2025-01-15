/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:50:06 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/13 15:52:32 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	list;
	char	*concat;
	char	**avgs;

	if (ac == 1)
		return (0);
	concat = ft_concat_input(ac, av);
	avgs = ft_split(concat, ' ');
	free(concat);
	if (ft_check_dup(avgs))
	{
		free_avgs(avgs);
		p_error();
	}
	ft_stack_init(&list, avgs);
	free_avgs(avgs);
	if (!ft_check_sorted(list.a))
		sort_stack(&list);
	ft_lst_free(&list);
	return (0);
}
