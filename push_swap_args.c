/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:08:34 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/15 18:55:41 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

void	free_stack(t_list **lst)
{
	t_list	*current;
	t_list	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*lst = NULL;
}

t_list	*form_list(int *array, int count)
{
	int		i;
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	i = 0;
	while (i < count)
	{
		new = ft_lstnew(array[i++]);
		if (!new)
		{
			free_stack(&lst);
			free(array);
			return (NULL);
		}
		ft_lstadd_back(&lst, new);
	}
	free(array);
	return (lst);
}

int	check_format(char **array)
{
	int	i;
	int	j;

	i = 1;
	while (array[i])
	{
		j = 0;
		if ((array[i][j] == '-' || array[i][j] == '+') && j == 0)
			j++;
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (i);
}

int	*get_args(char **array)
{
	int	*args;
	int	i;
	int	j;
	int	len;

	len = check_format(array) - 1;
	args = (int *)malloc(sizeof(int) * (len));
	if (!args)
		return (NULL);
	i = 0;
	while (array[++i] != NULL)
	{
		j = -1;
		while (++j < len)
		{
			if (ft_atoi(array[i]) == args[j])
			{
				write(2, "Error\n", 6);
				free(args);
				exit(1);
			}
		}
		args[i - 1] = ft_atoi(array[i]);
	}
	return (args);
}
