/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_upTo100_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:42:34 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/22 12:43:00 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_short_upto100(t_stacks_struct *str_stacks)
{
	int	i;
	int	j;
	int	pos_mov;

	i = 0;
	j = 0;
	ft_pb(str_stacks);
	ft_pb(str_stacks);
	if (str_stacks->stack_b[0] < str_stacks->stack_b[1])
		ft_rb(str_stacks);
	while (str_stacks->argca != 0)
	{		
		ft_calc_movs_a(str_stacks);
		ft_calc_movs_b(str_stacks);
		ft_sum_movs(str_stacks);
		ft_eject_movs(str_stacks);
		ft_pb(str_stacks);
		ft_free_stacks(str_stacks);
		j++;
	}
	ft_short_desc_stack_b(str_stacks);
	ft_return_shorted_to_stack_a(str_stacks);
}

int	ft_calc_movs_a(t_stacks_struct *str_stacks)
{	
	int	i;
	int	j;

	i = 0;
	str_stacks->mov_cant_a = malloc(sizeof(int) * str_stacks->argca);
	if (!str_stacks->mov_cant_a)
		return (00);
	if (ft_is_pair(str_stacks->argca))
		ft_pair2 (str_stacks);
	else
	{
		while (i < (str_stacks->argca / 2) + 1)
		{
			str_stacks->mov_cant_a[i] = i;
			i++;
		}
		j = i - 1;
		while (j > 0)
		{
			str_stacks->mov_cant_a[i] = j;
			i++;
			j--;
		}
	}
	return (0);
}

void	ft_pair2(t_stacks_struct *str_stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (str_stacks->argca / 2) + 1)
	{
		str_stacks->mov_cant_a[i] = i;
		i++;
	}
	j = --i;
	while (j > 0)
	{
		str_stacks->mov_cant_a[i] = j;
		j--;
		i++;
	}
}

int	ft_calc_movs_b(t_stacks_struct *str_stacks)
{	
	int	i;
	int	mov_cant;
	int	stack_a;

	str_stacks->stack_b_movs = malloc(sizeof(char *) * str_stacks->argca);
	if (!str_stacks->stack_b_movs)
		return (00);
	str_stacks->min = ft_calc_min(str_stacks->stack_b, str_stacks->argcb);
	str_stacks->max = ft_calc_max(str_stacks->stack_b, str_stacks->argcb);
	i = 0;
	str_stacks->mov_cant_b = malloc(sizeof(int) * str_stacks->argca);
	if (!str_stacks->mov_cant_b)
		return (00);
	while (i < str_stacks->argca)
	{
		ft_all_cases_to_sort(str_stacks, i);
		i++;
	}
	return (0);
}

void	ft_all_cases_to_sort(t_stacks_struct *str_stacks, int i)
{
	int	stack_a;
	int	stack_b_in_max;

	stack_a = str_stacks->stack_a[i];
	stack_b_in_max = str_stacks->stack_b[str_stacks->argcb - 1];
	if (str_stacks->stack_a[i] > str_stacks->max)
		ft_bigger_than_max(str_stacks, i);
	else if (str_stacks->stack_a[i] < str_stacks->min)
		ft_smaller_than_min(str_stacks, i);
	else if (stack_a > str_stacks->stack_b[0] && stack_a < stack_b_in_max)
		ft_between_0_and_argcb(str_stacks, i);
	else
		ft_between_max_and_min(str_stacks, stack_a, i);
}
