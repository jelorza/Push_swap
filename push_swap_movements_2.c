/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_movements_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:07:27 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/21 20:07:54 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_pb(t_stacks_struct *str_stacks)
{
	int	*stack_c;
	int	i;

	i = 0;
	if (str_stacks->argca > 0)
	{
		stack_c = malloc(sizeof(int) * str_stacks->argcb);
		while (i < str_stacks->argcb)
		{
			stack_c[i] = str_stacks->stack_b[i];
			i++;
		}
		ft_pb_update(str_stacks);
		i = 1;
		while (i < str_stacks->argcb)
		{
			str_stacks->stack_b[i] = stack_c[i - 1];
			i++;
		}
		free(stack_c);
		ft_stack_a_after_pb(str_stacks);
		write(1, "pb\n", 3);
	}
}

void	ft_pb_update(t_stacks_struct *str_stacks)
{
	free(str_stacks->stack_b);
	str_stacks->argcb = str_stacks->argcb + 1;
	str_stacks->stack_b = malloc(sizeof(int) * str_stacks->argcb);
	str_stacks->stack_b[0] = str_stacks->stack_a[0];
}

void	ft_stack_a_after_pb(t_stacks_struct *str_stacks)
{
	int	i;
	int	*stack_c;

	stack_c = malloc(sizeof(int) * str_stacks->argca);
	i = 0;
	while (i < str_stacks->argca)
	{
		stack_c[i] = str_stacks->stack_a[i];
		i++;
	}
	str_stacks->argca = str_stacks->argca - 1;
	free(str_stacks->stack_a);
	str_stacks->stack_a = malloc(sizeof(int) * str_stacks->argca);
	i = 0;
	while (i < str_stacks->argca)
	{
		str_stacks->stack_a[i] = stack_c[i + 1];
		i++;
	}
	free(stack_c);
}

void	ft_rb(t_stacks_struct *str_stacks)
{
	int	i;
	int	c;

	if (str_stacks->argcb > 1)
	{
		c = str_stacks->stack_b[0];
		i = 1;
		while (i < str_stacks->argcb)
		{
			str_stacks->stack_b[i - 1] = str_stacks->stack_b[i];
			i++;
		}
		str_stacks->stack_b[i - 1] = c;
	}
	write (1, "rb\n", 3);
}

void	ft_rrb(t_stacks_struct *str_stacks)
{
	int		c;
	int		i;
	char	*stack_c;

	stack_c = malloc(sizeof(int) * str_stacks->argcb);
	i = 0;
	c = str_stacks->stack_b[str_stacks->argcb - 1];
	while (i < str_stacks->argcb)
	{
		stack_c[i] = str_stacks->stack_b[i];
		i++;
	}	
	i = 1;
	while (i < str_stacks->argcb)
	{
		str_stacks->stack_b[i] = stack_c[i - 1];
		i++;
	}	
	str_stacks->stack_b[0] = c;
	free(stack_c);
	write(1, "rrb\n", 4);
}
