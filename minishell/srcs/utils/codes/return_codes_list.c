/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_codes_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:34:01 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 16:55:14 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	return_last_ret(t_mem *mem)
{
	t_ret_elem	*elem;

	elem = mem->ret_list->first;
	if (!elem)
		return (0);
	while (elem->next)
		elem = elem->next;
	if (elem->ret_code)
		return (elem->ret_code);
	return (0);
}

void	push_ret_elem(t_mem *mem, int ret_value)
{
	t_ret_elem	*elem;
	t_ret_elem	*tmp;

	tmp = NULL;
	elem = (t_ret_elem *)malloc(sizeof(t_ret_elem));
	if (!(elem))
		failure(EXIT_FAILURE, mem);
	elem->ret_code = ret_value;
	elem->next = NULL;
	if (!mem->ret_list->first)
		mem->ret_list->first = elem;
	else
	{
		tmp = mem->ret_list->first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	return ;
}
