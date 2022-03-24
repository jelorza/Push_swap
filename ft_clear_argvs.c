/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_argvs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:06:57 by jelorza-          #+#    #+#             */
/*   Updated: 2022/03/22 16:07:13 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*ft_clean_argvs(int argc, char **argv, int *num_counter)
{
	int	i;
	int	*to_int;
	int	j;

	j = 1;
	i = 0;
	if (argc == 2)
		to_int = ft_clean_argvs_with_quotations(argv[1], num_counter);
	else
	{
		to_int = (int *) malloc(sizeof(int) * (argc - 1));
		if (!to_int)
			return (NULL);
		while (j < argc)
		{
			to_int[i] = ft_atoi(argv[j]);
			i++;
			j++;
		}
	}
	return (to_int);
}

int	*ft_clean_argvs_with_quotations(char *str, int *num_counter)
{
	int	i;
	int	*to_int;
	int	j;

	j = 0;
	i = 0;
	to_int = (int *)malloc(sizeof(int) * ft_count_nbrs(str));
	if (!to_int)
		return (00);
	*num_counter = ft_count_nbrs(str);
	while (i < ft_count_nbrs(str))
	{
		to_int[i] = ft_split(str);
		i++;
	}
	return (to_int);
}

int	ft_count_nbrs(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{	
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		count++;
	}
	return (count);
}

int	ft_split(char *str)
{
	char		*str_numb;
	int			to_int;
	static int	i;
	int			j;

	j = 0;
	to_int = 0;
	str_numb = malloc(sizeof(char *) * ft_char_count(str));
	if (!str_numb)
		return (00);
	while (str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
	{
		str_numb[j] = str[i];
		i++;
		j++;
	}
	str_numb[j] = 00;
	to_int = ft_atoi(str_numb);
	free(str_numb);
	return (to_int);
}

int	ft_atoi(char *str)
{
	int					sign;
	size_t				i;
	long int	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	if (res * sign > 2147483647 || res * sign < -2147483648)
	{
		write (1, "Error\n", 6);
		exit (0);
	}
	return (res * sign);
}
