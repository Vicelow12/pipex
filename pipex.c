/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:17:04 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/05 01:08:28 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_all(char **argv, t_cmd *cmd, char **envp)
{
	cmd->possible_paths = ft_split(find_path(envp), ':');
	cmd->infile_fd = argv[1]; //TODO later, secure;
	cmd->outfile_fd = argv[4];
	cmd->command = malloc(sizeof(char **) * 2);
	cmd->command[0] = ft_split(argv[2], ' ');
	cmd->command[1] = ft_split(argv[3], ' ');
	pipe(cmd->pipe);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	int process_id[2];
	int	status;
	int		i;

	if (argc != 5)
		return (0);
	init_all(argv, &cmd, envp);
	
	i = 0;
	while (i < 2)
	{
		child_process(&cmd, envp, &process_id[i], i);
		i++;
	}
	close(cmd.pipe[0]);
	close(cmd.pipe[1]);
	i = 0;
	while (i < 2)
	{
		waitpid(process_id[i], &status, 0);
		i++;
	}
	
	return (status);
	
	//
	

}