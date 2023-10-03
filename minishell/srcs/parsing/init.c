/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:38:28 by malatini          #+#    #+#             */
/*   Updated: 2021/09/30 17:07:04 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/**
 * * Initialisation  de la structure principale qui va contenir
 ** tout ce qui aura ete malloque
 * @author: malatini
*/
t_mem	*init_mem(char **envp, bool env_set)
{
	t_mem	*mem;

	mem = (t_mem *)malloc(sizeof(t_mem));
	if (!mem)
		failure(-1, NULL);
	ft_memset(mem, 0, sizeof(t_mem));
	mem->cmd = NULL;
	mem->line = NULL;
	mem->buffer = NULL;
	if (env_set == true)
		mem->env = envp;
	else
		mem->env = NULL;
	mem->line = NULL;
	mem->ret_list = NULL;
	mem->env_test = NULL;
	return (mem);
}

void	define_mem(t_mem *mem, t_cmd *cmd, char *line, char **buffer)
{
	mem->cmd = cmd;
	mem->buffer = buffer;
	mem->line = line;
}

/**
** Initialise la liste chainee de commandes *
*** @author malatini
*/
t_cmd	*init_cmd(t_mem *mem)
{
	t_cmd	*cmd;

	cmd = NULL;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		failure(-1, mem);
	cmd->first = NULL;
	return (cmd);
}

/**
 ** Initialise un command elem *
 *** @author malatini
*/
t_cmd_elem	*init_cmd_elem(t_cmd *cmd, t_mem *mem)
{
	t_cmd_elem	*elem;

	(void)cmd;
	elem = (t_cmd_elem *)malloc(sizeof(t_cmd_elem));
	if (!elem)
		failure(-1, mem);
	ft_memset(elem, 0, sizeof(t_cmd_elem));
	elem->is_piped = false;
	elem->args_len = 0;
	elem->args = NULL;
	elem->next = NULL;
	elem->redir_type = R_NONE;
	elem->file = (t_file_list *)malloc(sizeof(t_file_list));
	if (!elem->file)
		failure(-1, mem);
	elem->file->first = NULL;
	elem->is_piped = false;
	elem->path = NULL;
	cmd->first = elem;
	return (elem);
}

/**
 **Initialisation de notre buffer de lecture *
*** @author: malatini
*/
char	*init_read_buffer(t_cmd *cmd, t_mem *mem)
{
	char	*buffer;

	(void)cmd;
	buffer = (char *)malloc(sizeof(char));
	if (!buffer)
		failure(-1, mem);
	buffer[0] = 0;
	return (buffer);
}