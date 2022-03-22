/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_to_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:06:01 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/22 16:06:36 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*ft_args_to_index(int *stack_a, int argc)
{
	int	j;
	int	*stack_b;

	j = 0;
	stack_b = ft_short_stack_a(stack_a, argc);
	stack_a = ft_change_to_index(stack_a, stack_b, argc);
	free(stack_b);
	stack_b = NULL;
	return (stack_a);
}

int	*ft_change_to_index(int *stack_a, int *stack_b, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		stack_a[i] = ft_find_index(stack_a[i], stack_b, argc);
		i++;
	}
	return (stack_a);
}

int	ft_find_index(int stack_a_index, int *stack_b, int argc)
{
	int	i;
	int	boolean;

	boolean = 1;
	i = 0;
	while (i < argc && boolean == 1)
	{
		if (stack_b[i] == stack_a_index)
			boolean = 0;
		else
			i++;
	}
	return (i);
}

int	*ft_short_stack_a(int *stack_a, int argc)
{
	int	i;
	int	j;
	int	c;
	int	*str;

	i = 0;
	j = 1;
	c = 0;
	str = malloc(sizeof(int) * argc);
	if (!str)
		return (NULL);
	while (i < argc)
	{
		str[i] = stack_a[i];
		i++;
	}
	i = 0;
	str = ft_swap(argc, str);
	return (str);
}

int	*ft_swap(int argc, int *str)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (i < argc)
	{
		while (j < argc)
		{
			if (str[i] > str[j])
			{
				c = str[i];
				str[i] = str[j];
				str[j] = c;
				j = i;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (str);
}
