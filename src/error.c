/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 19:16:08 by aliandie          #+#    #+#             */
/*   Updated: 2015/06/14 14:17:25 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void check_error(int ac, char **av, char **env)
{
	if (ac < 1)
	{
		ft_putendl("ERROR: Not Enough arg");
		exit(1);
	}
	if (!av[1])
	{
		ft_putendl("ERROR: arg");
		exit(1);
	}
	if (!env[0])
	{
		ft_putendl("ERROR: Environment Not Found");
		exit(1);
	}
}

void term(void)
{
	char			*name;
	struct termios	term;

	if ((name = getenv("TERM")) == NULL)
	{
		ft_putendl("ERROR: getenv");
		exit(1);
	}
	if (tgetent(NULL, name) == ERR)
	{
		ft_putendl("ERROR: tgetent");
		exit(1);
	}
	if (tcgetattr(0, &term) == -1)
	{
		ft_putendl("ERROR: tcgetattr");
		exit(1);
	}
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VTIME] = 1;
	term.c_cc[VMIN] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	ft_putstr_fd(tgetstr("vi", NULL), g_fd);
	ft_putstr_fd(tgetstr("ti", NULL), g_fd);
}
