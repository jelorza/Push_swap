/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_upTo100_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:43:33 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/22 12:44:16 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_sum_movs(t_stacks_struct *str_stacks)
{
	int	i;
	int	mov_cant_a;

	i = 0;
	str_stacks->sum_movs_a_b = malloc (sizeof(int) * str_stacks->argca);
	while (i < str_stacks->argca)
	{
		mov_cant_a = str_stacks->mov_cant_a[i];
		str_stacks->sum_movs_a_b[i] = mov_cant_a + str_stacks->mov_cant_b[i];
		i++;
	}
}

int	ft_calc_min_movs(t_stacks_struct *str_stacks)
{
	int	min_mov;
	int	i;
	int	j;

	i = 0;
	min_mov = 0;
	j = str_stacks->sum_movs_a_b[i];
	while (i < str_stacks->argca)
	{
		if (str_stacks->sum_movs_a_b[i] < j)
		{
			j = str_stacks->sum_movs_a_b[i];
			min_mov = i;
		}
		else
			i++;
	}
	return (min_mov);
}

void	ft_eject_movs(t_stacks_struct *str_stacks)
{
	int	pos_mov;
	int	i;

	i = 0;
	pos_mov = ft_calc_min_movs(str_stacks);
	if (ft_is_pair(str_stacks->argca))
		ft_pair(str_stacks, pos_mov);
	else
		ft_odd(str_stacks, pos_mov);
	while (i < str_stacks->mov_cant_b[pos_mov])
	{
		if (str_stacks->stack_b_movs[pos_mov] == 'u')
			ft_rb(str_stacks);
		else
			ft_rrb(str_stacks);
		i++;
	}
}

void	ft_pair(t_stacks_struct *str_stacks, int pos_mov)
{
	int	i;

	i = 0;
	if (pos_mov <= str_stacks->argca / 2)
	{
		while (i < str_stacks->mov_cant_a[pos_mov])
		{
			ft_ra(str_stacks);
			i++;
		}
	}
	else
	{
		while (i < str_stacks->mov_cant_a[pos_mov])
		{
			ft_rra(str_stacks);
			i++;
		}	
	}
}

void	ft_odd(t_stacks_struct *str_stacks, int pos_mov)
{
	int	i;

	i = 0;
	if (pos_mov < str_stacks->argca / 2 + 1)
	{
		while (i < str_stacks->mov_cant_a[pos_mov])
		{
			ft_ra(str_stacks);
			i++;
		}
	}
	else
	{
		while (i < str_stacks->mov_cant_a[pos_mov])
		{
			ft_rra(str_stacks);
			i++;
		}
	}
}
