/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_upTo100_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:43:06 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/22 12:43:15 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_bigger_than_max(t_stacks_struct *str_stacks, int i)
{
	int	mov_cant;

	mov_cant = ft_find_min (str_stacks->stack_b, str_stacks->argcb) + 1;
	if (mov_cant > str_stacks->argcb / 2)
	{
		str_stacks->mov_cant_b[i] = str_stacks->argcb - mov_cant;
		str_stacks->stack_b_movs[i] = 'd';
	}
	else
	{
		str_stacks->mov_cant_b[i] = mov_cant;
		str_stacks->stack_b_movs[i] = 'u';
	}
}

void	ft_smaller_than_min(t_stacks_struct *str_stacks, int i)
{
	int	mov_cant;

	mov_cant = ft_find_min(str_stacks->stack_b, str_stacks->argcb) + 1;
	if (mov_cant > str_stacks->argcb / 2)
	{
		str_stacks->mov_cant_b[i] = str_stacks->argcb - mov_cant;
		str_stacks->stack_b_movs[i] = 'd';
	}
	else
	{
		str_stacks->mov_cant_b[i] = mov_cant;
		str_stacks->stack_b_movs[i] = 'u';
	}
}

void	ft_between_0_and_argcb(t_stacks_struct *str_stacks, int i)
{
	int	mov_cant;

	mov_cant = str_stacks->argcb;
	if (mov_cant > str_stacks->argcb / 2)
	{
		str_stacks->mov_cant_b[i] = str_stacks->argcb - mov_cant;
		str_stacks->stack_b_movs[i] = 'd';
	}
	else
	{
		str_stacks->mov_cant_b[i] = mov_cant;
		str_stacks->stack_b_movs[i] = 'u';
	}
}

void	ft_between_max_and_min(t_stacks_struct *str_stacks, int stack_a, int i)
{	
	int	j;
	int	boolean;
	int	mov_cant;
	int	stack_b;

	boolean = 1;
	j = ft_find_position(str_stacks, stack_a);
	mov_cant = j + 1;
	if (mov_cant > str_stacks->argcb / 2)
	{
		str_stacks->mov_cant_b[i] = str_stacks->argcb - mov_cant;
		str_stacks->stack_b_movs[i] = 'd';
	}
	else
	{
		str_stacks->mov_cant_b[i] = mov_cant;
		str_stacks->stack_b_movs[i] = 'u';
	}
}

int	ft_find_position(t_stacks_struct *str_stacks, int stack_a)
{
	int	stack_b;
	int	boolean;
	int	j;

	boolean = 1;
	j = 0;
	while (j < str_stacks->argcb && boolean == 1)
	{
		stack_b = str_stacks->stack_b[j];
		if (stack_a < stack_b && stack_a > str_stacks->stack_b[j + 1])
			boolean = 0;
		else
			j++;
	}
	return (j);
}
