/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 18:38:26 by aliandie          #+#    #+#             */
/*   Updated: 2015/06/13 19:18:52 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	line(int p, int len, int p_min)
{
	if (p > len)
		p = p_min;
	else if (p < p_min)
		p = len;
	return (p);
}

int main(int ac, char **av, char **env)
{
	char	*path;
	int		p;
	char	b[3];
	t_tools	*tls;

	check_error(ac, av, env);
	path = ttyname(0);
	g_fd = open(path, O_WRONLY | O_NOCTTY);
	tls = tools_init(av + 1, ac);
	p = 0;
	term();
	signal(SIGINT, interupt);
	signal(SIGTSTP, stop);
	signal(SIGCONT, handle_cont);
	while (1)
	{
		p = line(p, tls->p_max, 0);
		ft_putstr_fd(tgetstr("cl", NULL), g_fd);
		getwinsize(tls, p);
		bzero(b, 3);
		read(0, b, 3);
		getkey(b, &p, &tls);
	}
	return (0);
}
