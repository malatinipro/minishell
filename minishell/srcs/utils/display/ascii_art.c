/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_art.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:46:30 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 15:43:23 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ascii_art(void)
{
	ft_putstr_fd("\033[1;36m        _       _     _          _ _ \n", 1);
	ft_putstr_fd("  /\\/\\ (_)_ __ (_)___| |__   ___| | |\n", 1);
	ft_putstr_fd(" /    \\| | '_ \\| / __| '_ \\ / _ \\ | |\n", 1);
	ft_putstr_fd("/ /\\/\\ \\ | | | | \\__ \\ | | |  __/ | |\n", 1);
	ft_putstr_fd("\\/    \\/_|_| |_|_|___/_| |_|\\___|_|_|\033[0m\n\n\n", 1);
	return ;
}
