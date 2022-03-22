/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:07:57 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/22 16:08:34 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_calc_max(int *stack, int argc)
{
	int	i;
	int	max;

	i = 0;
	max = stack[0];
	while (i < argc)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int	ft_calc_min(int *stack, int argc)
{
	int	i;
	int	min;

	i = 0;
	min = stack[0];
	while (i < argc)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	ft_is_pair(int argc)
{
	if (argc % 2 == 1)
		return (0);
	else
		return (1);
}

int	ft_find_min(int *stack, int argc)
{
	int	i;
	int	boolean;

	boolean = 1;
	i = 0;
	while (i < argc && boolean == 1)
	{
		if (stack[i] == ft_calc_min(stack, argc))
			boolean = 0;
		else
			i++;
	}
	return (i);
}

int	ft_char_count(char *str)
{
	static int	i;
	int			count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		count++;
		i++;
	}
	return (count);
}
