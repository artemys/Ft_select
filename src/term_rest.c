/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 15:01:02 by aliandie          #+#    #+#             */
/*   Updated: 2015/06/13 16:28:08 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_rest(void)
{
	struct termios	term;
	char			*name;

	name = getenv("TERM");
	tgetent(NULL, name);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(0, TCSADRAIN, &term);
	ft_putstr_fd(tgetstr("cl", NULL), g_fd);
	ft_putstr_fd(tgetstr("te", NULL), g_fd);
	ft_putstr_fd(tgetstr("ve", NULL), g_fd);
}
