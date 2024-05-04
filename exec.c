/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:50:12 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/05 01:11:55 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(t_cmd *cmd, char **envp, int *process_id, int i)
{
	//Faire des enfants pour lancer execve;
	//On va vouloir dup les FD.
	process_id[i] = fork();
	if (process_id[i] == -1)
		exit(EXIT_FAILURE); //Todo change this;
	
	if (process_id[i] == 0)
	{	
		do_dup(cmd, i);
		close(cmd->pipe[0]);
		close(cmd->pipe[1]);
		cmd->valid_path = find_valid_path(cmd, cmd->command[i]);
		write(2, "walked past valid path\n", 23);
		// printf("current value of valid path is %s\n", cmd->valid_path);
		if (cmd->valid_path)
			execve(cmd->valid_path, cmd->command[i], envp);
		free(cmd->valid_path);
		//EXIT ALL;
	}
	return (0);
}

void	do_dup(t_cmd *cmd, int i)
{
	int	file;
	if (i == 0)
	{
		file = open(cmd->infile_fd, O_RDONLY);
		if (!file)
			exit(EXIT_FAILURE);
		if (dup2(file, STDIN_FILENO) == -1)
			exit(EXIT_FAILURE);
		if (dup2(cmd->pipe[1], STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
	}
	if (i == 1)
	{
		file = open(cmd->outfile_fd, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (!file)
			exit(EXIT_FAILURE);
		if (dup2(cmd->pipe[0], STDIN_FILENO) == -1)
			exit(EXIT_FAILURE);
		if (dup2(file, STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
	}
	if (close(file) == -1)
		exit(EXIT_FAILURE);
	return;
}
