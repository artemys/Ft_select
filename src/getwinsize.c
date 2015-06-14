/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getwinsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 13:00:26 by aliandie          #+#    #+#             */
/*   Updated: 2015/06/13 20:02:31 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		getwinsize(t_tools *tls, int p)
{
	int				i;
	int				len;
	struct winsize	ws;
	int				win_max;

	i = 1;
	ioctl(0, TIOCGWINSZ, &ws);
	win_max = ws.ws_col / tls->col_s * ws.ws_row;
	tls->line = ws.ws_row;
	tls->col = ws.ws_col;
	tls->col_s = ft_strlen(tls->list[0]);
	while (tls->list[i])
	{
		len = ft_strlen(tls->list[i]);
		if (tls->col_s < len)
			tls->col_s = len;
		i++;
	}
	tls->col_s = tls->col_s + 3;
	if (tls->p_max + 5 > win_max)
		ft_putendl_fd("Window too small, please enlarge.", g_fd);
	else
		print_list(tls, p);
}
