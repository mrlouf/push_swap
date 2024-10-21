/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:53:40 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/18 18:54:48 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	free_stack_a(t_stack *stack)
{
	t_stack	*current;
	t_stack	*tmp;
	
	if (stack == NULL)
		return ;
	current = stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	stack = NULL;
}

void	free_stack_b(t_stack *stack)
{
	t_stack	*current;
	t_stack	*tmp;
	
	if (stack == NULL)
		return ;
	current = stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	stack = NULL;
}

void	free_stacks(t_stacks *stacks)
{
	free_stack_a(stacks->stack_a);
	free_stack_b(stacks->stack_b);
}