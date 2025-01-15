/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:10:53 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/14 12:13:33 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_response(t_list *list)
{
	if (ft_check_sorted(list->a) && list->b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_list	list;
	char	*concat;
	char	**avgs;
	char	*move;

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
	move = get_next_line(0);
	while (move)
	{
		exec_move(&list, move);
		move = get_next_line(0);
	}
	print_response(&list);
	return (ft_lst_free(&list), 0);
}
