/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 16:21:14 by aliandie          #+#    #+#             */
/*   Updated: 2015/06/13 19:15:16 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exit_select(t_tools *tls, char *b)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	term_rest();
	if (RETURN(b))
	{
		while (tls->list[i])
		{
			if (tls->selct[i] == 1)
			{
				ret = 1;
				ft_putstr(tls->list[i]);
				ft_putchar(' ');
			}
			i++;
		}
		if (ret == 1)
			ft_putstr("\n");
	}
	exit(0);
}
