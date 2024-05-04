/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:39:23 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/05 01:05:06 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_valid_path(t_cmd *cmd, char **current_cmd)
{
	int		i;
	char	*path;

	i = 0;
	if (access(current_cmd[0], X_OK) == 0)
		return (current_cmd[0]);
	while (cmd->possible_paths[i])
	{
		path = ft_strjoin(cmd->possible_paths[i], "/");
		path = ft_strjoin(path, current_cmd[0]);
		if(!path)
		{	
			write(2, "hi123\n", 6);
			exit(EXIT_FAILURE);
		}
		write(2, "hi\n", 3);
		if (access(path, X_OK) == 0)
		{	
			
			return (path);
		}
		free(path);
		i++;
	}
	// write(2, "hi2\n", 4);
	return(NULL);
	
}
char	*find_path(char**envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}