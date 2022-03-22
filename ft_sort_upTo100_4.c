/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_upTo100_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:44:23 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/22 12:45:45 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_free_stacks(t_stacks_struct *str_stacks)
{
	free(str_stacks->mov_cant_a);
	free(str_stacks->mov_cant_b);
	free(str_stacks->sum_movs_a_b);
	free(str_stacks->stack_b_movs);
}

void	ft_short_desc_stack_b(t_stacks_struct *str_stacks)
{
	int	min;

	min = ft_calc_max(str_stacks->stack_b, str_stacks->argcb);
	while (str_stacks->stack_b[0] != min)
	{
		if (min <= str_stacks->argcb / 2)
			ft_rb(str_stacks);
		else
			ft_rrb(str_stacks);
	}
}

void	ft_return_shorted_to_stack_a(t_stacks_struct *str_stacks)
{
	while (str_stacks->argcb != 0)
		ft_pa(str_stacks);
}

int	ft_calc_movs_for_b(int num, t_stacks_struct *str_stacks)
{
	int	i;
	int	boolean;

	boolean = 1;
	i = 0;
	while (i < str_stacks->argcb && boolean == 1)
	{
		if (num < str_stacks->stack_b[i] && num > str_stacks->stack_b[i + 1])
			boolean = 0;
		else
			i++;
	}
	return (i);
}
