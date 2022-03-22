/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:29:05 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/22 15:57:23 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

typedef struct stacks {
	int		*stack_a;
	int		*stack_b;
	int		argca;
	int		argcb;
	int		*mov_cant_a;
	int		*mov_cant_b;
	int		*sum_movs_a_b;
	int		min;
	int		max;
	char	*stack_b_movs;

}	t_stacks_struct;

int		ft_check_char(int argc, char **argv); // checamos si no hay caracteres
int		ft_atoi(char *str);
int		*ft_clean_argvs( int argc, char **argv, int *num_counter);
int		*ft_clean_argvs_with_quotations(char *str, int *num_counter);
int		ft_count_nbrs(char *str);
int		ft_split(char *str);
int		ft_char_count(char *str);
int		ft_check_repeated_numbs(int *str, int argc);
int		ft_check_maxMin_int(int *str);
int		*ft_args_to_index(int *stack_a, int argc);
void	ft_push_swap(int *stack_a, int *argc);
void	ft_char_error(int argc, char **argv);
int		*ft_short_stack_a(int *stack_a, int argc);
int		*ft_swap(int argc, int *str);
int		*ft_change_to_index(int *stack_a, int *stack_b, int argc);
int		ft_find_index(int stack_a_index, int *stack_b, int argc);
void	ft_sa(t_stacks_struct *str_stacks);
void	ft_sb(t_stacks_struct *str_stacks);
void	ft_ss(t_stacks_struct *str_stacks);
void	ft_pa(t_stacks_struct *str_stack);
void	ft_pa_update(t_stacks_struct *str_stack);
void	ft_stack_b_after_pa(t_stacks_struct *str_stacks);
void	ft_pb(t_stacks_struct *str_stack);
void	ft_pb_update(t_stacks_struct *str_stack);
void	ft_stack_a_after_pb(t_stacks_struct *str_stacks);
void	ft_ra(t_stacks_struct *str_stack);
void	ft_rb(t_stacks_struct *str_stack);
void	ft_rr(t_stacks_struct *str_stack);
void	ft_rra(t_stacks_struct *str_stack);
void	ft_rrb(t_stacks_struct *str_stack);
void	ft_rrr(t_stacks_struct *str_stack);
void	ft_short_upto3(t_stacks_struct *str_stack);
void	ft_stack_a_in0_ismin(t_stacks_struct *str_stack);
int		ft_check_ifis_shorted(t_stacks_struct *str_stacks);
void	ft_short_upto5(t_stacks_struct *str_stacks);
void	ft_between_max_min(t_stacks_struct *str_stacks);
void	ft_fit_from_b1(t_stacks_struct *str_stacks);
int		ft_min(t_stacks_struct *str_stacks);
void	ft_fit_from_b2(t_stacks_struct *str_stacks);
int		ft_ra_mov(t_stacks_struct *str_stacks, int i);
int		ft_rra_mov(t_stacks_struct *str_stacks, int i, int argca);
int		ft_find_min(int *stack, int argc);
void	ft_short_upto100(t_stacks_struct *str_stack);
void	ft_free_stacks(t_stacks_struct *str_stack);
int		ft_calc_movs_a(t_stacks_struct *str_stack);
void	ft_pair2(t_stacks_struct *str_stack);
int		ft_calc_movs_b(t_stacks_struct *str_stack);
void	ft_all_cases_to_sort(t_stacks_struct *str_stack, int i);
int		ft_is_pair(int argc);
int		ft_calc_movs_for_b(int num, t_stacks_struct *str_stack);
void	ft_sum_movs(t_stacks_struct *str_stack);
void	ft_eject_movs(t_stacks_struct *str_stack);
void	ft_pair(t_stacks_struct *str_stack, int pos_mov);
void	ft_odd(t_stacks_struct *str_stack, int pos_mov);
void	ft_bigger_than_max(t_stacks_struct *str_stack, int i);
void	ft_smaller_than_min(t_stacks_struct *str_stack, int i);
void	ft_between_0_and_argcb(t_stacks_struct *str_stack, int i);
int		ft_find_position(t_stacks_struct *str_stack, int stack_a);
void	ft_between_max_and_min(t_stacks_struct *str_stack, int stack_a, int i);
int		ft_calc_min_movs(t_stacks_struct *str_stack);
int		ft_calc_max(int *stack, int argc);
int		ft_calc_min(int *stack, int argc);
void	ft_return_shorted_to_stack_a(t_stacks_struct *str_stack);
void	ft_short_desc_stack_b(t_stacks_struct *str_stack);

#endif
