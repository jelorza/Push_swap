/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:46:33 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/22 16:10:51 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char **argv)
{
	int	j;
	int	*stack_a;
	int	num_counter;

	num_counter = 0;
	j = 0;
	if (argc > 1)
	{
		ft_char_error(argc, argv);
		stack_a = ft_clean_argvs(argc, argv, &num_counter);
		argc = argc - 1;
		if (num_counter > 0)
			argc = num_counter;
		if (ft_check_repeated_numbs(stack_a, argc))
		{
			free(stack_a);
			write (1, "Error", 15);
			return (0);
		}
		ft_push_swap(stack_a, &argc);
	}
	return (0);
}

void	ft_push_swap(int *stack_a, int *argca)
{
	int				i;
	t_stacks_struct	str_stacks;

	str_stacks.argcb = 0;
	str_stacks.stack_b = malloc(sizeof(int) * str_stacks.argcb);
	i = 0;
	str_stacks.argca = *argca;
	str_stacks.stack_a = ft_args_to_index(stack_a, *argca);
	if (ft_check_ifis_shorted(&str_stacks))
	{		
		if (str_stacks.argca <= 3)
			ft_short_upto3(&str_stacks);
		else if (str_stacks.argca > 3 && str_stacks.argca <= 5)
			ft_short_upto5(&str_stacks);
		else if (str_stacks.argca > 5 && str_stacks.argca <= 500)
			ft_short_upto100(&str_stacks);
	}
	free(str_stacks.stack_b);
	free(str_stacks.stack_a);
}
