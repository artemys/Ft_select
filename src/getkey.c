/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 13:33:57 by aliandie          #+#    #+#             */
/*   Updated: 2015/06/13 18:54:30 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	getkey(char *b, int *p, t_tools **tls)
{
	if (UP(b))
		(*p)--;
	else if (DOWN(b))
		(*p)++;
	if (SPACE(b))
	{
		(*tls)->selct[*p] = ((*tls)->selct[*p] == 0) ? 1 : 0;
		(*p) += ((*tls)->selct[*p] == 1) ? 1 : 0;
	}
	if (RETURN(b) || ESC(b))
		exit_select(*tls, b);
	if (DELETE(b) || BACKSPACE(b))
		delete_list(tls, p);
}
