/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:07:21 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/22 16:07:28 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_char_error(int argc, char **argv)
{
	if (ft_check_char(argc, argv))
	{
		write(1, "Error", 5);
		exit (0);
	}
}

int	ft_check_char(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	argc = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				if (argv[i][j] != ' ' && argv[i][j] != '-')
					return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_check_repeated_numbs(int *num, int argc)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (i < argc)
	{
		while (j < argc)
		{
			if (num[i] == num[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}
