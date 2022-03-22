/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_upTo5_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:20:40 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/21 20:25:14 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_short_upto5(t_stacks_struct *str_stacks)
{
	int	i;
	int	dif;

	dif = str_stacks->argca - 3;
	i = 0;
	while (i < dif)
	{
		ft_pb(str_stacks);
		i++;
	}
	ft_short_upto3(str_stacks);
	while (str_stacks->argcb != 0)
		ft_fit_from_b1(str_stacks);
}

void	ft_fit_from_b1(t_stacks_struct *str_stacks)
{
	int	i;
	int	stack_a_in0;

	stack_a_in0 = str_stacks->stack_b[0];
	i = 0;
	str_stacks->min = str_stacks->stack_a[0];
	str_stacks->max = str_stacks->stack_a[str_stacks->argca - 1];
	if (stack_a_in0 > str_stacks->max || stack_a_in0 < str_stacks->min)
		ft_between_max_min(str_stacks);
	else
		ft_fit_from_b2(str_stacks);
	str_stacks->min = ft_find_min(str_stacks->stack_a, str_stacks->argca);
	while (ft_min(str_stacks))
	{
		if (str_stacks->argca / 2 <= str_stacks->min)
			ft_rra(str_stacks);
		else
			ft_ra(str_stacks);
	}
}

void	ft_fit_from_b2(t_stacks_struct *str_stacks)
{
	int	i;
	int	boolean;
	int	argca;
	int	stack_b_in0;
	int	innext;

	argca = str_stacks->argca;
	boolean = 1;
	i = 0;
	while (i < argca && boolean == 1)
	{
		stack_b_in0 = str_stacks->stack_b[0];
		innext = str_stacks->stack_a[i + 1];
		if (stack_b_in0 > str_stacks->stack_a[i] && stack_b_in0 < innext)
		{
			i++;
			if (i > argca / 2)
				boolean = ft_rra_mov(str_stacks, i, argca);
			else
				boolean = ft_ra_mov(str_stacks, i);
		}
		else
			i++;
	}
}

int	ft_rra_mov(t_stacks_struct *str_stacks, int i, int argca)
{
	while (i < argca)
	{
		ft_rra(str_stacks);
		i++;
	}
	ft_pa(str_stacks);
	return (0);
}

int	ft_ra_mov(t_stacks_struct *str_stacks, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		ft_ra(str_stacks);
		j++;
	}
	ft_pa(str_stacks);
	return (0);
}
