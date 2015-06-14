/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 13:16:20 by aliandie          #+#    #+#             */
/*   Updated: 2015/06/13 19:21:35 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	display(t_tools *tls, int p, int i)
{
	if (tls->selct[i] == 1)
		ft_putstr_fd(tgetstr("mr", NULL), g_fd);
	if (i == p)
		ft_putstr_fd(tgetstr("us", NULL), g_fd);
	ft_putendl_fd(tls->list[i], g_fd);
	ft_putstr_fd(tgetstr("me", NULL), g_fd);
}

void	print_list(t_tools *tls, int p)
{
	int	i;
	int line;
	int col;

	i = 0;
	line = 0;
	col = 0;
	while (tls->list[i])
	{
		if ((line + 1) == tls->line)
		{
			line = 0;
			col = col + tls->col_s;
		}
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), col, line), g_fd);
		if (tls->selct[i] == 1 || i == p)
			display(tls, p, i);
		else
			ft_putendl_fd(tls->list[i], g_fd);
		i++;
		line++;
	}
}
