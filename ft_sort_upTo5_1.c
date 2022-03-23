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
	int min_pos;
	int j;

	dif = str_stacks->argca - 3;
	i = 0;

	while (i < dif)
	{
		j = 0;
		min_pos = ft_find_min (str_stacks->stack_a, str_stacks->argca);
		if (min_pos > str_stacks->argca / 2 )
		{
			min_pos = str_stacks->argca - min_pos;
			while (j < min_pos)
			{
				ft_rra(str_stacks);
				j++;
			}
		}
		else
		{
			while(j < min_pos)
			{
				ft_ra(str_stacks);
				j++;
			}
		}	
		ft_pb(str_stacks);
		i++;
	}
	ft_short_upto3(str_stacks);
	if (str_stacks->stack_b[0] < str_stacks->stack_b[1])
		ft_sb(str_stacks);
	ft_pa(str_stacks);
	ft_pa(str_stacks);
}
