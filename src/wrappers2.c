/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farges  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by farges            #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by farges           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_wrapper(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

int	waitpid_wrapper(pid_t *ptr, int *status)
{
	*ptr = waitpid(-1, status, 0);
	return (*ptr);
}

void	close_wrapper(int fd)
{
	if (close(fd) == -1)
		perror("close failed");
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <execinfo.h>
#include <unistd.h>

void print_stack_symbols_with_addr2line(void **buffer, int nptrs) 
{
	char cmd[512];
	for (int i = 0; i < nptrs; i++)
	{
snprintf(cmd, sizeof(cmd), "addr2line -f -p -e ./minishell %p", buffer[i]);
		system(cmd);
	}
}

void print_stack_trace(void)
{
    void *buffer[64];
    int nptrs = backtrace(buffer, 64);
	print_stack_symbols_with_addr2line(buffer, nptrs);
}

void close_wrapper(int fd)
{
    if (close(fd) == -1) {
        perror("close failed");
        print_stack_trace();  // This shows where close_wrapper was called from
        assert(0 && "close_wrapper failed");
    }
}*/
