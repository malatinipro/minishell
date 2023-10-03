/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:47:07 by malatini          #+#    #+#             */
/*   Updated: 2022/03/30 18:59:37 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/**
** Permet d'afficher comme env les variables d'environnement
** contenues dans la liste chainee.
* @author: malatini
*/
void	print_tab_env(t_env_list *env)
{
	t_env_elem	*elem;

	elem = env->first;
	while (elem)
	{
		if (elem->value && elem->display)
		{
			ft_putstr_fd(elem->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(elem->value, 1);
			ft_putstr_fd("\n", 1);
		}
		elem = elem->next;
	}
}

/**
** Permet de realiser env comme bash sous Linux (Ubuntu)
*@author: malatini
*/
int	ft_exec_env(t_env_list *env, t_mem *mem)
{
	if (env)
	{
		print_tab_env(env);
		push_ret_elem(mem, 0);
		return (0);
	}
	else
	{
		ft_putstr_fd("_=/usr/bin/env", 1);
		push_ret_elem(mem, 0);
	}
	return (0);
}