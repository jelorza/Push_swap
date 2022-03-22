/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_upTo5_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:21:09 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/21 19:29:59 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_min(t_stacks_struct *str_stacks)
{
	int	stack_a_in0;

	stack_a_in0 = str_stacks->stack_a[0];
	if (ft_calc_min(str_stacks->stack_a, str_stacks->argca) != stack_a_in0)
		return (1);
	else
		return (0);
}

void	ft_between_max_min(t_stacks_struct *str_stacks)
{
	if (str_stacks->stack_b[0] > str_stacks->max)
	{
		ft_pa(str_stacks);
		ft_ra(str_stacks);
	}	
	else
		ft_pa(str_stacks);
}
