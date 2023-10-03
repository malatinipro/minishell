/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:12:44 by malatini          #+#    #+#             */
/*   Updated: 2021/09/26 11:05:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/**
** Permet d'echapper les quotes a l'interieur de la value des vars d'env
* @author: malatini
*/
void	ft_putstr_fd_escape(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			write(fd, "\\", 1);
		write(fd, &str[i], 1);
		i++;
	}
}

/**
** Affiche la lise chainee de variables d'env comme export
* @author: malatini
*/
void	ft_print_tab_env_export(t_env_list *env)
{
	t_env_elem	*elem;

	elem = env->first;
	while (elem)
	{
		if (ft_strcmp(elem->key, "_"))
		{
			if (elem->value)
			{
				ft_putstr_fd("declare -x ", 1);
				ft_putstr_fd(elem->key, 1);
				ft_putstr_fd("=\"", 1);
				ft_putstr_fd_escape(elem->value, 1);
				ft_putstr_fd("\"\n", 1);
			}
			else
			{
				ft_putstr_fd("declare -x ", 1);
				ft_putstr_fd(elem->key, 1);
				ft_putstr_fd("\n", 1);
			}
		}
		elem = elem->next;
	}
}

/**
** Reproduit le comportement d'export sans argument
* @author: malatini
*/
int	ft_export_no_arg(t_cmd_elem *cmds, t_mem *mem)
{
	int			ret;
	t_env_list	*cpy;

	(void)cmds;
	(void)mem;
	ret = 0;
	cpy = cpy_env_list(mem);
	if (!cpy)
		return (0);
	bubble_sort(cpy);
	ft_print_tab_env_export(cpy);
	free_env_list(cpy);
	return (ret);
}

bool	found_char(char *str, char c)
{
	bool	found;
	int		i;

	i = 0;
	found = false;
	while (str[i])
	{
		if (str[i] == c)
			found = true;
		i++;
	}
	return (found);
}

bool	check_append(char *str)
{
	int		i;
	bool	append;

	i = 0;
	append = false;
	while (str[i])
	{
		if (str[i] == '+' && str[i + 1] && str[i + 1] == '=')
			append = true;
		i++;
	}
	return (append);
}