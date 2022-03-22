/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:40:59 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/21 20:08:46 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_sa(t_stacks_struct *str_stacks)
{
	int	i;
	int	num;

	i = 0;
	num = str_stacks->stack_a[0];
	if (str_stacks->argca > 1)
	{
		str_stacks->stack_a[0] = str_stacks->stack_a[1];
		str_stacks->stack_a[1] = num;
		write (1, "sa\n", 3);
	}
}

void	ft_sb(t_stacks_struct *str_stacks)
{
	int	i;
	int	num;

	i = 0;
	num = str_stacks->stack_b[0];
	if (str_stacks->argcb > 1)
	{
		str_stacks->stack_b[0] = str_stacks->stack_b[1];
		str_stacks->stack_b[1] = num;
		write (1, "sb\n", 3);
	}
}

void	ft_pa(t_stacks_struct *str_stacks)
{
	int	*stack_c;
	int	i;

	i = 0;
	if (str_stacks->argcb > 0)
	{
		stack_c = malloc(sizeof(int) * str_stacks->argca);
		while (i < str_stacks->argca)
		{
			stack_c[i] = str_stacks->stack_a[i];
			i++;
		}
		i = 1;
		ft_pa_update(str_stacks);
		while (i < str_stacks->argca)
		{
			str_stacks->stack_a[i] = stack_c[i - 1];
			i++;
		}
		free(stack_c);
		ft_stack_b_after_pa(str_stacks);
		write(1, "pa\n", 3);
	}
}

void	ft_pa_update(t_stacks_struct *str_stacks)
{
	free(str_stacks->stack_a);
	str_stacks->argca = str_stacks->argca + 1;
	str_stacks->stack_a = malloc(sizeof(int) * str_stacks->argca);
	str_stacks->stack_a[0] = str_stacks->stack_b[0];
}

void	ft_stack_b_after_pa(t_stacks_struct *str_stacks)
{
	int	i;
	int	*stack_c;

	stack_c = malloc(sizeof(int) * str_stacks->argcb);
	i = 0;
	while (i < str_stacks->argcb)
	{
		stack_c[i] = str_stacks->stack_b[i];
		i++;
	}
	str_stacks->argcb = str_stacks->argcb - 1;
	free(str_stacks->stack_b);
	str_stacks->stack_b = malloc(sizeof(int) * str_stacks->argcb);
	i = 0;
	while (i < str_stacks->argcb)
	{
		str_stacks->stack_b[i] = stack_c[i + 1];
		i++;
	}
	free(stack_c);
}
