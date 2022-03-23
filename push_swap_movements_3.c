/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_movements_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:09:19 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/21 20:11:03 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_ra(t_stacks_struct *str_stacks)
{
	int	i;
	int	c;

	i = 1;
	if (str_stacks->argca > 1)
	{
		c = str_stacks->stack_a[0];
		while (i < str_stacks->argca)
		{
			str_stacks->stack_a[i - 1] = str_stacks->stack_a[i];
			i++;
		}
		str_stacks->stack_a[i - 1] = c;
	}
	write (1, "ra\n", 3);
}

void	ft_rr(t_stacks_struct *str_stacks)
{
	ft_ra(str_stacks);
	ft_rb(str_stacks);
}

void	ft_rra(t_stacks_struct *str_stacks)
{
	int		c;
	int		i;
	int		*stack_c;

	stack_c = malloc(sizeof(int) * str_stacks->argca);
	i = 0;
	c = str_stacks->stack_a[str_stacks->argca - 1];
	while (i < str_stacks->argca)
	{
		stack_c[i] = str_stacks->stack_a[i];
		i++;
	}	
	i = 1;
	while (i < str_stacks->argca)
	{
		str_stacks->stack_a[i] = stack_c[i - 1];
		i++;
	}	
	str_stacks->stack_a[0] = c;
	free(stack_c);
	write(1, "rra\n", 4);
}	

void	ft_rrr(t_stacks_struct *str_stacks)
{
	ft_rra(str_stacks);
	ft_rrb(str_stacks);
}

void	ft_ss(t_stacks_struct *str_stacks)
{
	ft_sa(str_stacks);
	ft_sb(str_stacks);
}
