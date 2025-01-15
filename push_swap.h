/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:50:10 by mohaben-          #+#    #+#             */
/*   Updated: 2025/01/13 14:03:03 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_list
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tail_a;
	t_stack	*tail_b;
	int		size_a;
	int		size_b;
}	t_list;

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
long	ft_atoi(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
t_stack	*ft_lstnew(int data);
t_stack	*ft_lstlast(t_stack *stack);
void	ft_lstadd_back(t_list *list, t_stack *new);
void	ft_lst_free(t_list *list);
void	sa(t_list *list, int print);
void	sb(t_list *list, int print);
void	ss(t_list *list, int print);
void	pa(t_list *list, int print);
void	pb(t_list *list, int print);
void	ra(t_list *list, int print);
void	rb(t_list *list, int print);
void	rr(t_list *list, int print);
void	rra(t_list *list, int print);
void	rrb(t_list *list, int print);
void	rrr(t_list *list, int print);
void	p_error(void);
int		ft_isdigit(char c);
int		ft_isallspace(char *s);
int		ft_str_digit(char *s);
int		ft_not_valid(char *s);
int		ft_check_dup(char **avgs);
int		ft_len_avgs(int ac, char **av);
void	free_avgs(char **avgs);
char	*ft_concat_input(int ac, char **av);
int		ft_size_avgs(char **avgs);
void	ft_stack_init(t_list	*list, char **avgs);
int		ft_check_sorted(t_stack *a);
void	sort_stack(t_list *list);
void	sort_3(t_list *list);
void	push_min_sort4_5(t_list *list, int pos, int len_stack);
void	sort_4_5(t_list *list);
int		find_max(t_stack *stack);
int		find_pos_max(t_stack *stack);
void	push_to_a_sorted(t_list *list);
void	sort_range(t_list *list, int range_min, int range_max);
char	*get_next_line(int fd);
void	exec_move(t_list *list, char *move);

#endif