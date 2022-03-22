/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_upTo3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:59:41 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/21 11:30:12 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_short_upto3(t_stacks_struct *str_stacks)
{	
	if (ft_check_ifis_shorted(str_stacks))
	{
		str_stacks->max = ft_calc_max(str_stacks->stack_a, str_stacks->argca);
		str_stacks->min = ft_calc_min(str_stacks->stack_a, str_stacks->argca);
		if (str_stacks->argca == 2)
			ft_ra(str_stacks);
		else if (str_stacks->stack_a[0] == str_stacks->min)
			ft_stack_a_in0_ismin(str_stacks);
		else if (str_stacks->stack_a[str_stacks->argca - 1] == str_stacks->max)
			ft_sa(str_stacks);
		else if (str_stacks->stack_a[0] == str_stacks->max)
		{
			if (str_stacks->stack_a[str_stacks->argca - 1] == str_stacks->min)
			{
				ft_sa(str_stacks);
				ft_rra(str_stacks);
			}
			else
				ft_ra(str_stacks);
		}
		else
			ft_rra(str_stacks);
	}
}

int	ft_check_ifis_shorted(t_stacks_struct *str_stacks)
{
	int	i;

	i = 1;
	while (i < str_stacks->argca)
	{
		if (str_stacks->stack_a[i - 1] > str_stacks->stack_a[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_stack_a_in0_ismin(t_stacks_struct *str_stacks)
{
	ft_rra(str_stacks);
	ft_sa(str_stacks);
}
