/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:24:28 by elerazo-          #+#    #+#             */
/*   Updated: 2025/08/12 13:24:32 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

static void	fork_helper(t_shell *shell, t_cmd *cmd)
{
	if (setup_redirections(shell, cmd) != SUCCESS)
		exit(1);
	if (is_builtin(cmd->argv[0]))
		exit(exec_builtin(shell, cmd));
	else
		exec_external(shell, cmd);
}

static void	fork_wrapper(t_shell *shell, t_pipe *data, t_cmd *cmd)
{
	data->pid = fork();
	if (data->pid == -1)
	{
		perror("minishell: fork");
		exit(1);
	}
	if (data->pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (data->prev_read_end != -1)
		{
			if (wrapper_dup2(data->prev_read_end, STDIN_FILENO, shell) == 0)
				exit(shell->last_status);
			close_wrapper(data->prev_read_end);
		}
		if (cmd->next)
		{
			close_wrapper(data->pipe_fd[0]);
			if (wrapper_dup2(data->pipe_fd[1], STDOUT_FILENO, shell) == 0)
				exit(shell->last_status);
			close_wrapper(data->pipe_fd[1]);
		}
		fork_helper(shell, cmd);
	}
}

static void	set_pipe_data(t_pipe *data, t_shell *shell)
{
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
	if (wrapper_dup(&data->b_std[0], STDIN_FILENO, shell) == -1)
		exit(shell->last_status);
	if (wrapper_dup(&data->b_std[1], STDOUT_FILENO, shell) == -1)
		exit(shell->last_status);
	data->last_pid = -1;
	data->prev_read_end = -1;
}

static void	update_fd(t_pipe *data, t_cmd **cmd)
{
	if (data->prev_read_end != -1)
		close_wrapper(data->prev_read_end);
	if ((*cmd)->next != NULL)
	{
		close_wrapper(data->pipe_fd[1]);
		data->prev_read_end = data->pipe_fd[0];
	}
	else
		data->prev_read_end = -1;
	data->last_pid = data->pid;
	*cmd = (*cmd)->next;
}

void	execute_pipe(t_shell *shell, t_cmd *cmd)
{
	t_cmd	*cmd_iter;
	t_pipe	data;

	set_pipe_data(&data, shell);
	cmd_iter = cmd;
	while (cmd_iter)
	{
		if (cmd_iter->next)
		{
			if (pipe(data.pipe_fd) == -1)
			{
				perror("minishell: pipe");
				return ;
			}
		}
		fork_wrapper(shell, &data, cmd_iter);
		update_fd(&data, &cmd_iter);
	}
	if (data.prev_read_end != -1)
		close_wrapper(data.prev_read_end);
	if (data.last_pid != -1)
		wait_for_children(shell, data.last_pid);
	reset_std_fds(&*data.b_std, shell);
}
